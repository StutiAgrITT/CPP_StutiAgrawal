#include<iostream>

//created .o file and than ran nm command to get symbol table

int globalVariable = 4; //symbol type : D (Data)
int uninitializedGlobal; //B : block started by symbol
const int constantVariable = 100; //R : read only

int function_name(int x) { //function -> symbol type : T (Text)
    return x;
}

int main() { //T
    int x = 10;
    int z;
    std::cout << "Hello\n"; //U: undefined
}