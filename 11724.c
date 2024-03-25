//b, dfs(i, i)의 2번째 i 둘 다 사실상 기능 X
#include <stdio.h>

int X[1001][1001] = { 0, }, vi[1001] = { 0, };
int N, M;

void dfs(int a, int b) {
	X[a][b] = 0;
	X[b][a] = 0;
	for (int i = 1; i <= N; i++) {
		if (X[a][i] == 1 && !vi[i]) {
			vi[i] = 1;
			dfs(i, b);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	int a, b, com = 0;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		X[a][b] = 1;
		X[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (!vi[i]) {
			vi[i] = 1;
			dfs(i, i);
			com++;
		}
	}
	printf("%d\n", com);
}
