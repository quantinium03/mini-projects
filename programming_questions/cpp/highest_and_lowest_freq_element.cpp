#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::vector<int> int_vector{2, 2, 3, 4, 4, 2};
    std::size_t size = int_vector.size();

    std::sort(int_vector.begin(), int_vector.end());
    int largest = int_vector[size - 1];
    int smallest = int_vector[0];

    std::unordered_map<int, int> mpp;
    for (int i = 0; i < size; i++) {
        mpp[int_vector[i]]++;
    }

    int max_freq = 0, min_freq = size;
    int max_el = 0, min_el = 0;

    for (auto &i : mpp) {
        int count = i.second;
        int element = i.first;

        if (count > max_freq) {
            max_el = element;
            max_freq = count;
        }
        if (count < min_freq) {
            min_el = element;
            min_freq = count;
        }
    }
    std::cout << max_el << ' ' << min_el << std::endl;
    return 0;
}
