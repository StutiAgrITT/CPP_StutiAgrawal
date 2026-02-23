#include <iostream>

class Node {
    int data;
    Node* next;
public:
    Node(int x, Node* next = nullptr) : data(x), next(next) {}
};

int main() {
    Node a(1, NULL);
    Node b(2, NULL);
    return 0;
}

/*
(gdb) print a
$1 = {data = 1, next = 0x0}
(gdb) set var a.next = &b
(gdb) print a
$2 = {data = 1, next = 0x7fffffffdcf0}
*/