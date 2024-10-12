#include <iostream>

void print(int x);

int main(){
  int num;
  std::cin >> num;

  print(num);
}

void print(int x){
  if(x == 0){
    return;
  }
  print(x - 1);
  std::cout << x;
}
