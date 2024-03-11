#include <stdio.h>

int a[1000001] = { 0, };

int main() {
	int M, N;
	scanf("%d %d", &M, &N);
	
    a[1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = i * 2; j <= N; j += i) {
			a[j] = 1;
		}
	}

	for (int k = M; k <= N; k++) {
		if (a[k] == 0) printf("%d\n", k);
	}
}
