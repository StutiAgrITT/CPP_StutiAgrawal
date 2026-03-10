#include <iostream>
#include <list>

int main() {
    std::list<int> l = {1,2,3};

    l.push_front(0);
    l.push_back(4);

    for(auto it = l.begin(); it != l.end(); ++it)
        std::cout << *it << " ";
    
    return 0;
}
