#include <array>
#include <iostream>

// 1) Klassendefinition mit zwei Template-Parametern:
//    T         = Typ der Elemente
//    max_size  = Compile-Time-Konstante für die Array-Größe
template <typename T, unsigned int max_size>
class Stack {
    std::array<T, max_size> stack; // hier wird max_size verwendet
    int                     position;

  public:
    Stack() : position(-1) {}

    void push(T c);
    T    pop();
};

// 2) Out-of-class-Definition von push – Du siehst den Scope-Operator ::
template <typename T, unsigned int max_size>
void Stack<T, max_size>::push(T c) {
    if (position + 1 >= static_cast<int>(max_size)) {
        std::cerr << "Fehler: Stack voll!\n";
        return;
    }
    stack[++position] = c;
}

// 3) Out-of-class-Definition von pop
template <typename T, unsigned int max_size>
T Stack<T, max_size>::pop() {
    if (position < 0) {
        std::cerr << "Fehler: Stack leer!\n";
        return T(); // Default-Konstruktion
    }
    return stack[position--];
}

int main() {
    // Hier wird max_size = 5 (und T = int)
    Stack<int, 5> intStack;
    intStack.push(10);
    intStack.push(20);
    std::cout << "intStack.pop(): " << intStack.pop() << "\n"; // 20
    std::cout << "intStack.pop(): " << intStack.pop() << "\n"; // 10

    // Und hier max_size = 3 (und T = double)
    Stack<double, 3> dblStack;
    dblStack.push(3.14);
    dblStack.push(2.71);
    std::cout << "dblStack.pop(): " << dblStack.pop() << "\n"; // 2.71
    std::cout << "dblStack.pop(): " << dblStack.pop() << "\n"; // 3.14

    return 0;
}
