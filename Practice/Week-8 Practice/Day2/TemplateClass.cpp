#include <iostream>

template <class T>

class Vector {
public:
    T* arr;
    T size;
    Vector(T n) {
        size = n;
        arr = new T[size];
    }

    T dotProduct(Vector &v) {
        T d = 0;
        for (T i = 0; i < size; i++) {
            d += this->arr[i] * arr[i];
        }
        return d;
    }
};

int main() {
    Vector<int> v1(3);
    Vector<int> v2(3);
    v1.arr[0] = 1;
    v1.arr[1] = 2;
    v1.arr[2] = 3;
    v2.arr[0] = 1;
    v2.arr[1] = 2;
    v2.arr[2] = 3;
    std::cout << v1.dotProduct(v2) << '\n';
    return 0;
}