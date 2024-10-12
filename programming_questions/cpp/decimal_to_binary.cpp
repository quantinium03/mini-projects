#include <iostream>

int main(void){
  int n;
  std::cout << "Enter a number: ";
  std::cin >> n;

  int i = 0;
  
  int binaryarr[32];
  while(n > 0){
    binaryarr[i] = n % 2;
    n /= 2;
    i++;
  }

  for(int j = i - 1;j >= 0;j--){
    std::cout << binaryarr[j];
  }
}
