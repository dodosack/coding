#include <iostream>

class Human {
  public:
    std ::string city      = "default City";
    std::string  name      = "default Name";
    std::string  ocupation = "Default Job";
    int          age       = 0;

    void eat() { std::cout << "This Person is eating\n"; }
    void drink() { std::cout << "This Person is drinking\n"; }
    void sleep() { std::cout << "This Person ist sleeping\n"; }
};
int main() {
    Human human1;

    human1.name      = "Rick";
    human1.age       = 23;
    human1.ocupation = "Jobless Nigga";
    Human human2;
    std ::cout << human1.name << '\n';
    std ::cout << human1.age << '\n';
    std ::cout << human1.ocupation << '\n';

    std ::cout << human2.name << '\n';
    std ::cout << human2.age << '\n';
    std ::cout << human2.ocupation << '\n';

    human1.eat();
    human1.sleep();
    human1.drink();
    return 0;
}