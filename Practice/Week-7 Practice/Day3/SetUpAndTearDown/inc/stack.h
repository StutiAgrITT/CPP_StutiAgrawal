#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

class Stack {
private:
    std::vector<int> data;

public:
    void push(int value);
    void pop();
    int top() const;
    bool isEmpty() const;
    int size() const;
};

#endif