#include <iostream>
#include <string>

int main() {
    std::string s1 = "Hallo";
    std::string s2 = " Welt";
    
     s1 = "neu";
    std::string s3 = s1 + s2;        // "Hallo Welt"
    std::string s4 = s1 + " Welt";   // ebenfalls "Hallo Welt"

    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;

    return 0;
}