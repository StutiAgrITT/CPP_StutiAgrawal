#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> v1 = {1,2,3};
    std::vector<int> v2(3);
    
    std::copy(v1.begin(), v1.end(), v2.begin());
    for(int x : v2)
        std::cout << x << " ";
    return 0;

}