#include <cmath>
#include <iostream>

int main() {
    int num_1, count = 0;
    std::cin >> num_1;
    int orig_num = num_1;

    while (num_1 != 0) {
        count++;
        num_1 /= 10;
    }
    if (orig_num == 0) {
        count = 1;
    }

    num_1 = orig_num;
    int result = 0;
    while (num_1 != 0) {
        int digit = num_1 % 10;
        result = result + pow(digit, count);
        num_1 /= 10;
    }

    if (result == orig_num) {
        std::cout << "true";
    } else {
        std::cout << "false";
    }
}
