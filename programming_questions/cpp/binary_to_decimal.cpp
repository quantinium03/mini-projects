#include <iostream>
#include <cmath>
int main() {
  u_int64_t binary;
  std::cout << "Enter a binary number: ";
  std::cin >> binary;

  int decimal = 0, i = 0;
  while (binary != 0){
    int rem = binary% 10;
    binary /= 10;
    decimal += rem * pow(2, i);
    i++;
  }

  std::cout << decimal;
  return 0;
}
