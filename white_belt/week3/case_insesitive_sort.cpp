//
// Created by ivan on 04.08.2021.
//
#include <iostream>
#include <algorithm>
#include <vector>

bool comp(std::string s1, std::string s2){
    for (auto& el: s1){
        el =  tolower(el);
    }
    for (auto& el: s2){
        el = tolower(el);
    }

    std::vector<std::string> strings = {s1, s2};
    std::sort(strings.begin(), strings.end());
    if (strings[0] == s1){
        return true;
    }
    else{
        return false;
    }
}

void caseInsesitiveSort(std::vector<std::string>& strings){
//    std::vector<std::string> lowered(strings.size());
//
//    for (int i = 0; i < strings.size(); i++){
//        for (char letter: strings[i]){
//            lowered[i].push_back(tolower(letter));
//        }
//    }

    std::sort(strings.begin(), strings.end(), comp);
}

//int main(){
//    int n;
//    std::cin >> n;
//    std::vector<std::string> strings(n);
//    for (int i = 0; i < n; i++){
//        std::cin >> strings[i];
//    }
//
//    // std::vector<std::string> result(n);
//    caseInsesitiveSort(strings);
//
//    for (auto res: strings){
//        std::cout << res << " ";
//    }
//
//}