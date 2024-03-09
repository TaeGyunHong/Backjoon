#include <iostream>
using namespace std;

int main() {
    int num, max = 0, a;
    for (int i = 0; i < 9; i++) {
        cin >> a;
        if (max < a) {
            max = a;
            num = i + 1;
        }
    }
    cout << max << '\n' << num;
}
