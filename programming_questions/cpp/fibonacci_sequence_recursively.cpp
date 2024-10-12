#include <iostream>

void fibonacci(int num, int current = 0, int next = 1);

int main() {
    int num;
    std::cin >> num;

    fibonacci(num);
}

void fibonacci(int num, int current, int next) {
    if (num <= 0) {
        return;
    }
    std::cout << current << " ";
    fibonacci(num - 1, next, current + next);
}
