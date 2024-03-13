#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++ ) {
        cout << i << "\n";
    }//endl사용 - 버퍼 비우는 작업도 같이 하므로 시간초과
}
