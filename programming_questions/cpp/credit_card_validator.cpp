#include <iostream>
#include <string>

void identifyCardIssuer(const std::string &card_number);
void validateCard(const std::string &card_number);

int main() {
  std::string card_number{};
  std::cout << "Enter the credit card number: ";
  std::cin >> card_number;

  if (card_number.length() >= 13 && card_number.length() <= 16) {
    validateCard(card_number);
  } else {
    std::cout << "Invalid Card" << std::endl;
  }

  return 0;
}

void identifyCardIssuer(const std::string &card_number) {
  char firstDigit = card_number.at(0);

  if (firstDigit == '4') {
    std::cout << "Visa" << std::endl;
  } else if (firstDigit == '5') {
    char secondDigit = card_number.at(1);
    if (secondDigit >= '1' && secondDigit <= '5') {
      std::cout << "MasterCard" << std::endl;
    } else {
      std::cout << "Invalid Card" << std::endl;
    }
  } else if (firstDigit == '3') {
    char secondDigit = card_number.at(1);
    if (secondDigit == '4' || secondDigit == '7') {
      std::cout << "American Express" << std::endl;
    } else {
      std::cout << "Invalid Card" << std::endl;
    }
  } else {
    std::cout << "Invalid Card" << std::endl;
  }
}

void validateCard(const std::string &card_number) {
  int sum = 0;

  for (int i = card_number.length() - 1, alternate = 1; i >= 0;
       i--, alternate ^= 1) {
    int digit = card_number[i] - '0';
    digit *= (1 + alternate);
    digit -= (digit > 9) ? 9 : 0;
    sum += digit;
  }

  if (sum % 10 == 0) {
    identifyCardIssuer(card_number);
  } else {
    std::cout << "Invalid Card" << std::endl;
  }
}
