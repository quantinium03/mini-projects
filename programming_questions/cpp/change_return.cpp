#include <iostream>

int main(void){
  std::cout << "Enter the total amount of money: ";
  int cents, quarters = 25, dimes = 10, nickels = 5, pennies = 1, i, j, k ,l;
  std::cin >> cents;

  for (i = 0; cents >= quarters; i++) {
    cents = cents - quarters;
  }

  for (j = 0; cents >= dimes; j++) {
    cents = cents - dimes;
  }

  for (k = 0; cents >= nickels; k++) {
    cents = cents - nickels;
  }

  for (l = 0; cents >= pennies; l++) {
    cents = cents - pennies;
  }

  std::cout << "quarters: " << i << "\ndimes: " << j 
            << "\nnickels: " << k << "\npennies: " << l << std::endl;
  return 0;
}

