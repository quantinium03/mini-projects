#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

void printFibonacciSeries(int num,  boost::multiprecision::cpp_int current = 0,  boost::multiprecision::cpp_int next = 1);

int main() {
    int num;
    std::cout << "Enter the number of terms in the Fibonacci series: ";
    std::cin >> num;

    std::cout << "Fibonacci Series:" << std::endl;
    printFibonacciSeries(num); 

    return 0;
}

void printFibonacciSeries(int num, boost::multiprecision::cpp_int current, boost::multiprecision::cpp_int next) {
    if (num > 0) {
        std::string big_number = boost::multiprecision::to_string(current);
        std::cout << big_number << std::endl; 
        printFibonacciSeries(num - 1, next, current + next);
    }
}
/*
void printFibonacciSeries(int num, int num_1, int num_2) {
  for (int i = 0; i < num; ++i) {
    if (i == 0) {
      std::cout << num_1 << std::endl;
      continue;
    }
    if (i == 1) {
      std::cout << num_2 << std::endl;
      continue;
    }

    int next = num_1 + num_2;
    num_1 = num_2;
    num_2 = next;

    std::cout << next << std::endl;
  }
}
*/
