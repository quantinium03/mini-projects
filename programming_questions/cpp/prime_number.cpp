#include <cmath>
#include <iostream>

bool isPrime(u_int64_t n);

int main(void) {
  u_int64_t n{1};

  std::cout << "Enter a number: ";
  std::cin >> n;

  while (isPrime(n) == false) {
    n++;
  }
  std::cout << n << std::endl;

  return 0;
}

bool isPrime(u_int64_t n) {
  if (n <= 1) {
    return false;
  }
  if (n == 2) {
    return true;
  }

  if (n % 2 == 0) {
    return false;
  }
  for (int i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
