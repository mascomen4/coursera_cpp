//
// Created by ivan on 06.08.2021.
//

#include "Person_with_updating_dict.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Person_with_updating_dict {
public:
    void ChangeFirstName(int year, const string& first_name) {
        pair<string, string> full_name = getFullName(year);
        names.insert({year, {first_name, full_name.second}});
        names[year] = {first_name, full_name.second};
    }

    void ChangeLastName(int year, const string& last_name) {
        pair<string, string> full_name = getFullName(year);
        names.insert({year, {full_name.first, last_name}});
        names[year] = {full_name.first, last_name};
    }

    string GetFullName(int year) {
        auto full_name = getFullName(year);
        // check if the entries are empty
        bool flag_first = (full_name.first == "");
        bool flag_second = (full_name.second == "");

        if (flag_first && flag_second){
            return "Incognito";
        }
        else if (flag_first){
            return full_name.second + " with unknown first name";
        }
        else if (flag_second){
            return full_name.first + " with unknown last name";
        }
        else{ // we have the first and the second name
            return full_name.first + " " + full_name.second;
        }
        // string fullName = (names[year].first == "") ? "" names[year].first + names[year].second;
    }

private:
    map<int, pair<string, string>> names = {};
    // TODO: Update the dictionary after the the name or lastName was updated in the yearly years.
    int findClosestYear(int year){
        int closestYear = 0;
        auto testing = names.begin();
        auto testing_2 = names.end();
        // if the map is empty, assign the current year
        if (testing == testing_2){
            closestYear = year;
            // closestYear = testing->first;
        }
        else{
            for (auto it = names.begin(); ((it->first<=year) && (it!=names.end())); ++it){
                closestYear = it->first;
            }
        }
        return closestYear;
    }

    pair<string, string> getFullName(int year){
        auto smallest_year = names.begin()->first; // begin() is iterator
        if (year > smallest_year){
            int closest_year = findClosestYear(year);
            // pair<string, string> full_name = names[closest_year];
            return names[closest_year];
        }
        else{
            return names[year];
            // pair<string, string> full_name = names[year];
        }
//        else{
//            pair<string, string> full_name =
//        }
    }
};

//int main() {
//    Person_with_updating_dict person;
//
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
//    for (int year : {1969, 1970}) {
//        cout << person.GetFullName(year) << endl;
//    }
//
//    return 0;
//}
