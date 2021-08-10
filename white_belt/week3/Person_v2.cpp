//
// Created by ivan on 07.08.2021.
//

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        names[year] = {first_name, names[year].second};
    }

    void ChangeLastName(int year, const string& last_name) {
        names[year] = {names[year].first, last_name};
    }

    string GetFullName(int year) {
        // получаем имя и фамилию по состоянию на год year
        map<int, string> first_names, last_names = {};
        for (auto it = names.begin(); it != names.end(); ++it){
            if (!it->second.first.empty()){
                first_names[it->first] = it->second.first;
            }
            if (!it->second.second.empty()){
                last_names[it->first] = it->second.second;
            }
        }
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);

        // если и имя, и фамилия неизвестны
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";

            // если неизвестно только имя
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";

            // если неизвестна только фамилия
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";

            // если известны и имя, и фамилия
        } else {
            return first_name + " " + last_name;
        }
    }

    string GetFullNameWithHistory(int year) {
        /*
         * If the year is bigger than the smallest year in the dictionary, then find the nearest name and the
         * nearest lastName
         * If the year is equal to the smallest year in the dictionary
         * */
        pair<string, string> full_name = {"", ""};
        vector<string> add_names, add_last_names = {}; // extension for the 2nd ex.

        // fill add_names and add_last_names, fill the full_name
        for (auto it = names.begin(); ((it!=names.end()) && (it->first <= year)); ++it){
            auto curr_name = it->second;
            if (curr_name.first != ""){
                full_name = {curr_name.first, full_name.second};
                add_names.push_back(curr_name.first);
            }
            if (curr_name.second != ""){
                full_name = {full_name.first, curr_name.second};
                add_last_names.push_back(curr_name.second);
            }
        }

        // extension for the 2nd ex. Call the function with the corresponding calls.
        return processName(full_name, add_names, add_last_names);
//        if (!add_names.empty()){
//            if (!add_last_names.empty()){
//                return processName(full_name, add_names, add_last_names);
//            }
//            else{
//                return processName(full_name, add_names);
//            }
//        }
//        else{
//            if (!add_last_names.empty()){
//                return processName(full_name, add_names, add_last_names);
//            }
//            else{
//                return processName(full_name);
//
//            }
//        }
    }

private:
    map<int, pair<string, string>> names = {};

    // Needed for the GetFullName()
    static string FindNameByYear(const map<int, string>& names, int year) {
        string name;  // изначально имя неизвестно

        // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
        for (const auto& item : names) {
            // если очередной год не больше данного, обновляем имя
            if (item.first <= year) {
                name = item.second;
            } else {
                // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
                break;
            }
        }

        return name;
    }

    static string createStringFromVector(const vector<string>& input){
        string res = " (";
        for (auto el: input){
            res += el + ", ";
        }
        res = string(res.begin(), res.end() - 2);
        if (!res.empty()){
            res += ")";
        }
        return res;
    }

    static vector<string> cleanNames(vector<string>& names_to_clean){
        vector<string> clean_add_names = {};
        string last_el = names_to_clean[names_to_clean.size() - 1];
        string curr_name = names_to_clean[0];
        for (auto i = 1; i <= names_to_clean.size() - 1; ++i){
            if (curr_name == names_to_clean[i]){
                continue;
            }
            else{
                clean_add_names.push_back(curr_name);
                curr_name = names_to_clean[i];
            }
        }
        return clean_add_names;
    }

    static string processName(const pair<string, string>& full_name, vector<string> add_names={}, vector<string> add_last_names={}){

        bool flag_first = full_name.first.empty();
        bool flag_second = full_name.second.empty();
        vector<string> clean_add_names, clean_add_last_names;
        if (!add_names.empty()){
            clean_add_names = cleanNames(add_names);
            reverse(clean_add_names.begin(), clean_add_names.end());
        }
        if (!add_last_names.empty()){
            clean_add_last_names = cleanNames(add_last_names);
            reverse(clean_add_last_names.begin(), clean_add_last_names.end());
        }

        string add_names_string = createStringFromVector(clean_add_names);
        string add_last_names_string = createStringFromVector(clean_add_last_names);

        if (flag_first and flag_second){
            return "Incognito";
        }
        else if (flag_first){
            return full_name.second + add_last_names_string + " with unknown first name";
        }
        else if (flag_second){
            return full_name.first + add_names_string + " with unknown last name";
        }
        else{ // we have the first and the second name
            return full_name.first + add_names_string + " " + full_name.second + add_last_names_string;
        }
    }
};

//void providedTest(Person person){
//    person.ChangeFirstName(1965, "Polina");
//    person.ChangeLastName(1967, "Sergeeva");
//    for (int year : {1900, 1965, 1990}) {
//        cout << person.GetFullName(year) << endl;
//    }
//
//    person.ChangeFirstName(1970, "Appolinaria");
//    for (int year : {1969, 1970}) {
//        cout << person.GetFullName(year) << endl;
//    }
//
//    person.ChangeLastName(1968, "Volkova");
//    for (int year : {1901, 1902, 1968, 1969, 1970, 2001}) {
//        cout << year << " " << person.GetFullName(year) << endl;
//    }
//}

//void providedTest2(Person person){
//    person.ChangeFirstName(1900, "Eugene");
//    person.ChangeLastName(1900, "Sokolov");
//    person.ChangeLastName(1910, "Sokolov");
//    person.ChangeFirstName(1920, "Evgeny");
//    person.ChangeLastName(1930, "Sokolov");
//    cout << person.GetFullNameWithHistory(1940) << endl;
//}
//
//void providedTest3(Person person){
//    person.ChangeFirstName(1965, "Polina");
//    person.ChangeLastName(1967, "Sergeeva");
//    for (int year : {1900, 1965, 1990}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    person.ChangeFirstName(1970, "Appolinaria");
//    for (int year : {1969, 1970}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    person.ChangeLastName(1968, "Volkova");
//    for (int year : {1969, 1970}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    person.ChangeFirstName(1990, "Polina");
//    person.ChangeLastName(1990, "Volkova-Sergeeva");
//    cout << person.GetFullNameWithHistory(1990) << endl;
//
//    person.ChangeFirstName(1966, "Pauline");
//    cout << person.GetFullNameWithHistory(1966) << endl;
//
//    person.ChangeLastName(1960, "Sergeeva");
//    for (int year : {1960, 1967}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    person.ChangeLastName(1961, "Ivanova");
//    cout << person.GetFullNameWithHistory(1967) << endl;
//}
//
//void providedTest4(Person person) {
//    person.ChangeFirstName(1965, "Polina");
//    person.ChangeFirstName(1965, "Appolinaria");
//
//    person.ChangeLastName(1965, "Sergeeva");
//    person.ChangeLastName(1965, "Volkova");
//    person.ChangeLastName(1965, "Volkova-Sergeeva");
//
//    for (int year : {1964, 1965, 1966}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//}
//
//void myTest(Person person){
//    person.ChangeLastName(1901, "Podmogilnyi");
//    person.ChangeFirstName(1902, "Ivan");
//    person.ChangeFirstName(1900, "John");
//    person.ChangeLastName(1899, "Damyan");
//    person.ChangeFirstName(1899, "Local");
//
//    for (int year: {1898, 1899, 1900, 1901, 1902, 2000}){
//        cout << year << ' ' << person.GetFullName(year) << endl;
//    }
//}
//
//void myTest2(Person person){
//    person.ChangeLastName(1897, "Lomot");
//    person.ChangeLastName(1898, "Lomot2");
//    person.ChangeLastName(1901, "Podmogilnyi");
//    person.ChangeLastName(1902, "Podmogilnyi");
//    person.ChangeLastName(1903, "Podmogilnyi");
//    person.ChangeLastName(1904, "Podmogilnyi");
//    person.ChangeFirstName(1902, "Ivan");
//    person.ChangeFirstName(1900, "John");
//    person.ChangeLastName(1899, "Damyan");
//    person.ChangeFirstName(1899, "Local");
//
//    for (int year: {1897, 1898, 1899, 1900, 1901, 1902, 1903, 1904, 1950, 2000}){
//        cout << year << " " << person.GetFullNameWithHistory(year) << endl;
//    }
//}
//
//
//int main() {
//    Person person2, person3, person4;
//
////    providedTest2(person2);
////    providedTest3(person3);
////    providedTest4(person4);
//
//    //providedTest(person1);
//    //myTest(person2);
//    myTest2(person2);
//
//    /* Test cases for the 1st assignment:
//     *  ---- 1 ----
//     *
//     * 1901 Incognito, 1902 Incognito, 2001 Appolinaria Volkova
//     * 1968 Polina Volkova
//     *
//     *  ---- 1 ----
//     *
//     *
//     *
//     *
//     *  ---- 2 ----
//     *
//     *  Filled dict: {1901: {"", Podmogilnyi}, 1902: {Ivan, ""}, 1900: {John: ""}, 1899: {"", Damyan},
//     *      1899: {Local, ""}}
//     *  1898 Incognito
//     *  1899 Local Damyan
//     *  1900 John Damyan
//     *  1901 John Podmogilnyi
//     *  1902 Ivan Podmogilnyi
//     *  2000 Ivan Podmogilnyi
//     *
//     *  ----- 2 -----
//     *
//     *
//     *
//     * Test cases for the 2nd assignment;
//     *  ----- 3 -----
//     * 1897 Lomot with unknown first name
//     * 1898 Lomot2 (Lomot) with unknown first name
//     * 1899 Local Damyan
//     * 1900 John (Local) Damyan
//     * 1901 John (Local) Podmogilnyi (Damyan)
//     * 1902 Ivan (John, Local) Podmogilnyi (Damyan)
//     * 2000 Ivan (John, Local) Podmogilnyi (Damyan)
//     *  ----- 3 -----
//     * */
//
//    return 0;
//}