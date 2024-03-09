#include <iostream>
using namespace std;

int main() {
    int a, b, c, sum;
    int count[10] = {0,};

    cin >> a;
    cin >> b;
    cin >> c;
    sum = a * b * c;
    
    while(sum > 0) {
        count[sum%10] += 1;
        sum /= 10;
    }

    for(int i = 0; i < 10; i++) {
        cout << count[i] << endl;
    }
}
