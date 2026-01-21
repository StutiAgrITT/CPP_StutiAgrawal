//we can have same names in c++ as function overloading and namespaces are supported
//so compiler changes the name

int add(int a, int b) {     //_Z3addii
    return a + b;
}

int add(int a, int b, int c) {  //_Z3addiii
    return a + b + c;
}

int add (char a, char b) {  //_Z3addcc
    return (int) a + b;
}

float subtract(float a) {   //_Z8subtractf
    return a - 1;
}

int main() {
    int x = add(5, 3);
    int y = add(2, 5, 6);
    int z = add('2', '3');
}