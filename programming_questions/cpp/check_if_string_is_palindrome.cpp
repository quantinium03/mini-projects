#include <iostream>

void reverseString(std::string &str, std::size_t start, std::size_t end);

int main() {
    std::string str{};
    std::cin >> str;
    std::size_t size = str.size();
    std::string orig_str = str;

    reverseString(str, 0, size - 1);

    if (orig_str == str) {
        std::cout << "it is a palindrome" << std::endl;
    } else {
        std::cout << "it is not a palindrome" << std::endl;
    }
}

void reverseString(std::string &str, std::size_t start, std::size_t end) {
    if (start < end) {
        std::swap(str[start], str[end]);
        reverseString(str, start + 1, end - 1);
    }
}
