#include <iostream>

int main() {
    double matrix[3][3] = {0};
    double *ptr = &matrix[1][1];

    *(ptr + 2) = 3; //which changed?
    //1,1 + 1 -> 1,2 + 1 -> 2,0

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            std::cout << *(*(matrix + row) + col) << " ";
        }
        std::cout << '\n';
    }
    return 0;
}