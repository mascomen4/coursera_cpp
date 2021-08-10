//
// Created by ivan on 31.07.2021.
//
#include "iostream"
#include "vector"

void MoveStrings(std::vector<std::string>& source, std::vector<std::string>& destination){
    for (std::string el: source){
        destination.push_back(el);
    }
    source.clear();
}

//int main(){
//    std::vector<std::string> a = {"b", "c", "d"};
//    std::vector<std::string> b = {"a"};
//
//    MoveStrings(a, b);
//
//    std::cout << "Elements of b" << std::endl;
//    for (std::string el : b){
//        std::cout << el << " ";
//        std::cout << std::endl;
//    }
//    std::cout << "Length of a " << a.size();
//
//}