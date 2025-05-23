#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;


int main() {
std::ostringstream oss;
oss << 123 << " ist eine Zahl";
std::string result = oss.str(); // result = "123 ist eine Zahl"


    
int i = 1234;
std::cout << std::uppercase << std::showbase;
std::cout << "Hex: " << std::hex << i << std::endl;
std::cout << std::scientific << std::setprecision(5) << i / 100.0 << std::endl;
}