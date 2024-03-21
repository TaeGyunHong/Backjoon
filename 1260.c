#include <stdio.h>

int con[1001][1001] = { 0, }, vi[1001] = { 0, };

void dfs(int start, int comnum) {
	vi[start] = 1;
	printf("%d ", start);
	for (int i = 1; i <= comnum; i++) {
		if (con[start][i] == 1 && vi[i] == 0) dfs(i, comnum);
	}
}

void bfs(int start, int comnum) {
	int vi[1001] = { 0, };
	int queue[1001] = { 0, };
	int front = 0, rear = 0;

	queue[rear++] = start;
	vi[start] = 1;

	while(front < rear) {
		int tmp = queue[front++];
		printf("%d ", tmp);
		for (int i = 1; i <= comnum; i++) {
			if (con[tmp][i] == 1 && vi[i] == 0) {
				queue[rear++] = i;
				vi[i] = 1;
			}
		}
	}
}

int main() {
	int comnum, granum, start;
	scanf("%d %d %d", &comnum, &granum, &start);

	int a, b;
	for (int i = 0; i < granum; i++) {
		scanf("%d %d", &a, &b);
		con[a][b] = 1;
		con[b][a] = 1;
	}

	dfs(start, comnum);
	printf("\n");
	bfs(start, comnum);
}
