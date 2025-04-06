
#include <string>

class customer {

    std::string  _name;
    float        _balance;
    static float _interest;

  public:
    customer() {};
    void set_customer(std::string name) {
        _name = name;
    };
    void pay_in(float pay) {
        _balance += pay;
    };
    void add_interest() {
        _balance = _balance * (1 + _interest);
    };
};

float customer::_interest = 2.0;


int main() {

    customer c1;
    c1.set_customer("adsam");
    c1.pay_in(3000);
    c1.add_interest();
    
}