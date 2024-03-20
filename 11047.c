#include <stdio.h>

int main() {
	int K, x, count = 0;
	scanf("%d %d", &x, &K);
	int *N = (int *)malloc(x * sizeof(int));
	for (int i = 0; i < x; i++) {
		scanf("%d", &N[i]);
	}

	for (int i = x - 1; i >= 0; i--) {
		count += K / N[i];
		K %= N[i];
	}
	printf("%d", count);

	free(N);
}
