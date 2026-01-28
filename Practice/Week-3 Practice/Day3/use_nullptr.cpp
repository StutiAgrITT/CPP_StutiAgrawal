#include <iostream>

void print(int x) {
	std::cout << "print(int): " << x << '\n';
}

void print(int* ptr) {
	std::cout << "print(int*): " << (ptr ? "non-null\n" : "null\n");
}

int main() {
	int x{ 5 };
	int* ptr{ &x };

	print(ptr);  // always calls print(int*) because ptr has type int* (good)
	print(0);    // always calls print(int) because 0 is an integer literal (hopefully this is what we expected)

	// print(NULL); ambiguous, matches both

	print(nullptr); // always calls print(int*)

	return 0;
}