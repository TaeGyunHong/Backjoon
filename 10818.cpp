#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int min = 1000001;
	int max = -1000001;

	int N;
	cin >> N;

	int input;
	for(int i = 0; i < N; i++) {
		cin >> input;

		if (input < min) {
			min = input;
		}
		if (input > max) {
			max = input;
		}
	}

	cout << min << " " << max;
}
