//
// Created by ivan on 25.07.2021.
//
#include <iostream>
#include <vector>

int Factorial(int number){
    int factorial = 1;

    if (number < 0){
        return factorial;
    }
    for (int i = 1; i <= number; i++){
        factorial = factorial * i;
    }
    return factorial;
}

//int main(){
//    // Test cases
//    std::vector<int> test_cases = {1, -2, 4};
//    for (int test_case: test_cases){
//        std::cout << Factorial(test_case) << std::endl;
//    }
//}
