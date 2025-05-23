#include <iostream>
int main() {
int i = 1;
std::cout << std::showbase << std::uppercase;
std::cout << "Eingabe: ";
std::cin >> std::hex >> i;
std::cout << "Dec: " << std::dec << i << std::endl;
std::cout << "Hex: " << std::hex << i << std::endl;
std::cout << "Oct: " << std::oct << i << std::endl;
return 0;
}