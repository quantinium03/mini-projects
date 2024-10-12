#include <iostream>
#include <set>
#include <numeric>

int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int num_1, num_2;
    std::cin >> num_1 >> num_2;

    //int result = gcd(num_1, num_2);
    int result = std::gcd(num_1, num_2);

    std::cout << result << std::endl;
}
