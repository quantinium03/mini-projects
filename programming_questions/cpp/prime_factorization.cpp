#include <cmath>
#include <iostream>

int main(void) {
  u_int64_t n{1};

  std::cout << "Enter a number: " ;
  std::cin >> n;

  while (n % 2 == 0) {
    std::cout << 2 << " ";
    n = n / 2;
  }

  for (int i = 3; i * i <= n; i = i + 2) {
    while (n % i == 0) {
      std::cout << i << " ";
      n = n / i;
    }
  }

  if (n > 2) {
    std::cout << n;
  }

  std::cout << " " ;
}
