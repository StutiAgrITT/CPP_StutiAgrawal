#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int x, Node* next = nullptr) : data(x), next(next) {}
};

int main() {
    Node a(1, NULL);
    Node b(2, NULL);
    std::cout << a.data << " " << a.next << '\n';
    std::cout << b.data << " " << b.next << '\n';
    return 0;
}