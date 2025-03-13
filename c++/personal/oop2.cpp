#include <iostream>

class Car {

  public:
    std ::string make;
    std ::string model;
    int          year;
    std ::string colour;

    void accelarate() {

        std::cout << "U stepped on the gas\n";
    }

    void brake() {

        std ::cout << "You stepped on the brakes!\n";
    }
};
