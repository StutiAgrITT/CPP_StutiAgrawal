#include<iostream>

//this program checks whether cin fails
//with diff inputs like 12ab, abc, 12.34, large number

int main(){
    int number;
    std::cin >> number;
    if(std::cin.fail()){
        std::cout << "Failed" << std::endl;
    }
    else{
        std::cout << "Not Failed" << std::endl;
    }
    std::cout << number << std::endl;
}