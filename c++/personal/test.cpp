#include <iostream>
using namespace std;

namespace Auto
{
    int speed = 100;
}

namespace Fahrrad
{
    int speed = 25;
}

int main()
{
    int i;
    std ::cin >> i;
    std::cout << "Du hast die Zahl " << i << " eingeben.\n";    
    cout << "Auto Geschwindigkeit: " << Auto::speed << endl;
    cout << "Fahrrad Geschwindigkeit: " << Fahrrad::speed << endl;
    return 0;
}

