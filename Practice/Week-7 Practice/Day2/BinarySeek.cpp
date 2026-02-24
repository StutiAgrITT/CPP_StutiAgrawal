#include <iostream>
#include <fstream>

int main() {
    std::ofstream file("files/bin.dat", std::ios::binary);
    int arr[3] = {10, 20, 30};
    file.write((char*)arr, sizeof(arr));
    file.close();

    std::ifstream in("files/bin.dat", std::ios::binary);
    in.seekg(sizeof(int));
    int x;
    in.read((char*)&x, sizeof(int));
    std::cout << x << '\n';
    return 0;
}