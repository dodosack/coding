#include <iostream>

using namespace std;              //  <-- Semikolon ergänzen!

template <typename l>
l my_max(l x, l y)
{
    return (x > y) ? x : y;
}

int main()
{
    cout << my_max<int>(1, 2)  << endl;   // 2
    cout << my_max<char>('A','B') << endl; // 1
    return 0;
}
