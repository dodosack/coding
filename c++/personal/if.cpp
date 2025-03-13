#include "array"
#include <iostream>

using namespace std;

int main() {
  array<int, 6> lotto = {1, 2, 3, 4, 5, 49};
  for (int num : lotto) {
    cout << num << endl;
  }

  return 0;
}
