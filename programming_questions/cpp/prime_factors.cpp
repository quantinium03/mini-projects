#include <iostream>
#include <set>

int main() {
    int num;
    std::set<int> num_set;

    std::cin >> num;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            num_set.insert(i);
        }
    }

    for (auto &i : num_set) {
        std::cout << i << ' ';
    }
}
