#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, sum = 0;
	string x;
	cin >> n;
	cin >> x;

	for (int i = 0; i < n; i++) {
		sum += x[i] - '0';
	}
	cout << sum;
}
