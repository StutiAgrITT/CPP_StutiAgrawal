#include<iostream>

const int return_const(){
    return 4;
}

int main(){
    const int x = 10;
    //const int y -> not valid

    int y = return_const();
    y = 5; // valid

    const int arr[5] = {1, 2, 3, 4, 5}; //all become const
    //arr[2] = 7; -> invalid
    return 0;

}
