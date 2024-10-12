#include <iostream>

int sum(int x);

int main() {
    int num;
    std::cin >> num;

    int sum_of_nums = sum(num);
    std::cout << sum_of_nums;
    return 0;
}

int sum(int x) {
    if (x == 0) {
        return 0;
    }
    return x + sum(x - 1);
}
