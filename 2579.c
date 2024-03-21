//dp
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);
	int* X = (int*)malloc((N + 1) * sizeof(int));
	int* Y = (int*)malloc((N + 1) * sizeof(int));

	for (int i = 0; i < N; i++) {
		scanf("%d", &X[i + 1]);
	}
	Y[0] = 0;
	Y[1] = X[1];
	Y[2] = X[1] + X[2];

	//안 밟은 이후 2가지 패턴 중 하나 반복
	for (int i = 3; i <= N; i++) {
		Y[i] = (Y[i - 2] + X[i]) > (Y[i - 3] + X[i - 1] + X[i]) ? Y[i - 2] + X[i] : Y[i - 3] + X[i - 1] + X[i];
	}

	printf("%d", Y[N]);
}
