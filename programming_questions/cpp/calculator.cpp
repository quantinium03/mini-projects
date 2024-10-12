#include <cmath>
#include <iostream>

float addNumber(float num_1, float num_2);
float subtractNumber(float num_1, float num_2);
float multiplyNumber(float num_1, float num_2);
float divideNumber(float num_1, float num_2);
float powerNumber(float num_1, float num_2);

int main(void) {
  float num_1, num_2;
  float ans;
  std::cout << "Enter number 1: ";
  std::cin >> num_1;

  std::cout << "Enter number 2: ";
  std::cin >> num_2;

  char c;
  std::cout << "Enter the operation you wanna do(+,-,*,/,^): ";
  std::cin >> c;

  switch (c) {
  case '+':
    ans = addNumber(num_1, num_2);
    break;
  case '-':
    ans = subtractNumber(num_1, num_2);
    break;
  case '*':
    ans = multiplyNumber(num_1, num_2);
    break;
  case '/':
    ans = divideNumber(num_1, num_2);
    break;
  case '^':
    ans = powerNumber(num_1, num_2);
    break;
  default:
    std::cout << "please enter a valid operation" << std::endl;
  }

  std::cout << num_1 << c << num_2 << "=" << ans << std::endl;
  return 0;
}

float addNumber(float num_1, float num_2) { return num_1 + num_2; }
float subtractNumber(float num_1, float num_2) { return num_1 - num_2; }
float multiplyNumber(float num_1, float num_2) { return num_1 * num_2; }
float divideNumber(float num_1, float num_2) {
  if (num_2 != 0) {
    return num_1 / num_2;
  } else {
    std::cout << "infinity" << std::endl;
    return num_1 / num_2;
  }
}
float powerNumber(float num_1, float num_2) { return pow(num_1, num_2); }
