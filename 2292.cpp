#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    if (n == 1) 
        cout << "1";
    else {
        int i = 1;
        int sum = 1;
        while (n > sum) {
            sum += i * 6;
            i++;
        }
        cout << i;
    }
}
