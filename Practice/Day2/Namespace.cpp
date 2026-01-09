#include<iostream>
using namespace std;

namespace myNameSpace{
    int x = 184;
}

using namespace myNameSpace;

int main(){
    cout << x << endl;
    // without using namespace:
    // std::cout << myNameSpace::x << endl;
    return 0;
}