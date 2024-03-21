#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, sum = 0, tmp;
	scanf("%d", &N);
	int *T = (int *)malloc(N * sizeof(int));

	for (int i = 0; i < N; i++) {
		scanf("%d", &T[i]);
	}

	//버블정렬
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (T[j] > T[j + 1]) {
				tmp = T[j];
				T[j] = T[j + 1];
				T[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		sum += T[i] * (N - i);
	}

	printf("%d", sum);
}
