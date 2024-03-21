#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);
	int *X = (int *)malloc((N + 1) * sizeof(int));

	//bottom-up 방식
	X[2] = 1;
	X[3] = 1;

	int i = 4;
	while (i <= N) {
		X[i] = X[i - 1] + 1;
		if (i % 3 == 0) X[i] = X[i] < X[i / 3] + 1 ? X[i] : X[i / 3] + 1;
		if (i % 2 == 0) X[i] = X[i] < X[i / 2] + 1 ? X[i] : X[i / 2] + 1;
		i++;
	}
	printf("%d", X[N]);
}
