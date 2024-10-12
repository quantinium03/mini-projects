#include <iostream>
#include <vector>
#include <algorithm>

void reverseArray(std::vector<int> &int_vector, std::size_t start,
                  std::size_t end);

int main() {
    std::vector<int> int_vector{5, 4, 3, 2, 1};
    std::size_t size = int_vector.size();

    reverseArray(int_vector, 0, size - 1);
    //std::reverse(int_vector.begin(), int_vector.end());

    for (auto &i : int_vector) {
        std::cout << i << ' ';
    }
}

void reverseArray(std::vector<int> &int_vector, std::size_t start,
                  std::size_t end) {
    if (start <= end) {
        std::swap(int_vector[start], int_vector[end]);
        reverseArray(int_vector, start + 1, end - 1);
    }
}
