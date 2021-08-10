//
// Created by ivan on 06.08.2021.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class SortedStrings {
public:
    void AddString(const string& s){
        strings.push_back(s);
    }

    vector<string> GetSortedStrings(){
        vector<string> strings_sorted = strings;
        sort(strings_sorted.begin(), strings_sorted.end());
        return strings_sorted;
    }

private:
    vector<string> strings = {};
};
//
//void PrintSortedStrings(SortedStrings& strings) {
//    for (const string& s : strings.GetSortedStrings()) {
//        cout << s << " ";
//    }
//    cout << endl;
//}

//int main() {
//    SortedStrings strings;
//
//    strings.AddString("first");
//    strings.AddString("third");
//    strings.AddString("second");
//    PrintSortedStrings(strings);
//
//    strings.AddString("second");
//    PrintSortedStrings(strings);
//
//    return 0;
//}
