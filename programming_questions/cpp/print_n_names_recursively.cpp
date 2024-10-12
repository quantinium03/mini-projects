#include <iostream>

void printNTimes(std::string name, int num);

int main() {
    std::string name{"Quantinium\n"};
    int num;
    std::cin >> num;

    printNTimes(name, num);
}

void printNTimes(std::string name, int num) {
    if (num == 0) {
        return;
    }
    std::cout << name;
    printNTimes(name, num - 1);
}
