#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

int main() {
    std::vector<std::string> words = {"apple", "banana", "cherry"};
    std::vector<std::string> upper(words.size());

    std::transform(words.begin(), words.end(), upper.begin(),
        [](const std::string& str) {
            std::string temp = str;
            std::transform(temp.begin(), temp.end(), temp.begin(),
                [](char c) {
                    return std::toupper(c);
                });
            return temp;
        });

    for (const std::string& w : upper) {
        std::cout << w << " ";
    }

    return 0;
}
