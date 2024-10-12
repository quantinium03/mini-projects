#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {1, 2, 3, 1, 2, 1};
    int size = arr.size();
    std::vector<bool> visited(size, false);

    for (std::size_t i = 0; i < arr.size(); i++) {
        if (visited[i] == true) {
            continue;
        }
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
        std::cout << arr[i] << " " << count << std::endl;
    }

    return 0;
}

