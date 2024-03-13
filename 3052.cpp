#include <iostream>
using namespace std;
int main() {
    int count = 0, n, a[42] = { 0, };

    for (int i = 0; i < 10; i++){
    cin >> n;
    a[n % 42]++;
    }

    for (int i = 0; i < 42; i++ ) {
        if (a[i] != 0) count++;
    }
    
    cout << count;
}
