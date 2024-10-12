#include <iostream>

int main(void){
  double cost_of_a_sqm_tile{0.00};
  double length_of_floor{0.00}, width_of_floor{0.00};
  
  std::cout << "Enter the length of floor(in metres): ";
  std::cin >> length_of_floor;
  
  std::cout << "Enter the width of floor(in metres): ";
  std::cin >> width_of_floor;

  std::cout << "Enter the cost of tile(dollar per square metres): ";
  std::cin >> cost_of_a_sqm_tile;

  double cost_of_tile = length_of_floor * width_of_floor * cost_of_a_sqm_tile;

  std::cout << "The cost of tile to cover a WxH floor is: " << cost_of_tile << std::endl;
}
