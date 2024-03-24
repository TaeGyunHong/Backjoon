#include <stdio.h>

int G[50][50] = { 0, }, M, N;

void dfs(int a, int b) {
	G[a][b] = 0;
	if (a + 1 < M && G[a + 1][b] == 1) dfs(a + 1, b);
	if (a - 1 >= 0 && G[a - 1][b] == 1) dfs(a - 1, b);
	if (b + 1 < N && G[a][b + 1] == 1) dfs(a, b + 1);
	if (b - 1 >= 0 && G[a][b - 1] == 1) dfs(a, b - 1);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int K;
		scanf("%d %d %d", &M, &N, &K);

		int a, b;
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &a, &b);
			G[a][b] = 1;
		}

		int count = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (G[i][j] == 1) {
					dfs(i, j);
					count++;
				}
			}
		}
		printf("%d\n", count);
	}
}
