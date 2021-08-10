//
// Created by ivan on 31.07.2021.
//
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> Reversed(const std::vector<int>& v){
    std::vector<int> vCopy = v;
    std::reverse(vCopy.begin(), vCopy.end());
    return vCopy;


}
//
//int main(){
//    std::vector<int> myVector = {1,2,3,4};
//    std::vector<int> reversedVector = Reversed(myVector);
//
//    for (auto v: reversedVector){
//        std::cout << v;
//    }
//}
