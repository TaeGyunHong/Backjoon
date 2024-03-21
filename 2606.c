#include <stdio.h>

int con[101][101] = { 0, }, vi[101] = { 0, }, count = 0;

void dfs(int s, int comnum) {
	vi[s] = 1;
	count++;

	for (int i = 1; i <= comnum; i++) {
		if (con[s][i] == 1 && vi[i] == 0) dfs(i, comnum);
	}
}

int main() {
	int comnum, granum;
	scanf("%d\n %d", &comnum, &granum);

	int a, b;
	for (int i = 0; i < granum; i++) {
		scanf("%d %d", &a, &b);
		con[a][b] = 1;
		con[b][a] = 1;
	}

	dfs(1, comnum);
	printf("%d", count - 1);
}
