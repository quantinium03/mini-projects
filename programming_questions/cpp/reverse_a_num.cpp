#include <iostream>
#include <climits>

int reverseNumber(int x);

int main(void) {
    int num;
    std::cin >> num;
    
    int number = reverseNumber(num);
    
    std::cout << number << std::endl;
}

int reverseNumber(int x){
    int result = 0;
    if(x == 0){
        return 0;
    }
    while(x){
        result = result * 10 + (x % 10);
        x /= 10;
    }

    if(result > INT_MAX || result < INT_MIN){
        return 0;
    } 
    return result;
}
