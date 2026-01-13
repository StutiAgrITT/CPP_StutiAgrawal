#include<iostream>

int test_function(){
    static int x = 0;
    x++;
    std::cout << x << std::endl;
    return x;
}

int main(){
    int x = test_function();
    x++; //doesnt change the static x
    test_function();
    test_function();
}
