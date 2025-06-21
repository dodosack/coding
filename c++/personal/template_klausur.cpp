#include <array>
#include <iostream>
using namespace std;
template <typename T>
class Stack {
    array<T, 10> stack;
    int position = -1;

public:
    void push(T value) { stack[++position] = value; }
    T pop() { return stack[position--]; }
};

int main() {
    Stack<int> intStack;
    Stack<double> doubleStack;

    intStack.push(5);
    cout << intStack.pop() << endl;

    doubleStack.push(3.14);
    cout << doubleStack.pop() << endl;
}
