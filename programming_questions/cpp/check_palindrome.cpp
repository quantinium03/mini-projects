#include <iostream>

bool isPalindrome(int x);

int main(void) {
    int num;
    std::cin >> num;

    if (isPalindrome(num) == 0) {
        std::cout << "false";
    } else {
        std::cout << "true";
    }
}

bool isPalindrome(int x) {
    int orig_x = x;
    if (x < 0) {
        return false;
    }
    long long result = 0;
    while (x != 0) {
        result = result * 10 + (x % 10);
        x /= 10;
    }
    if (result != orig_x) {
        return false;
    }
    return true;
}
