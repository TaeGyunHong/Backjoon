#include <iostream>
using namespace std;

int main() {
    int n, m, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        int bo = 1;
        if (m <= 1) continue;
        for (int j = 2; j <= m - 1; j++) {
            if (m % j == 0) bo = 0;
        }
        if (bo == 1) count++;
    }
    cout << count;
}
