#include <iostream>

int factorial(int x);

int main() {
    int num;
    std::cin >> num;

    int fact = factorial(num);
    std::cout << fact;
    return 0;
}

int factorial(int x) {
    if (x == 0) {
        return 1;
    }
    return x * factorial(x - 1);
}
