//행 = n, y	열 = m, x
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
	int m, n, day;
} queue;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int M, N, day = 0, front = 0, back = 0;
void BFS(int** a, queue* q, int x, int y);

int main() {
	scanf("%d %d", &M, &N);
	int fullcount = M * N;

	int** a = (int**)calloc(N, sizeof(int*));
	for (int i = 0; i < N; i++) {
		a[i] = (int*)calloc(M, sizeof(int));
	}

	queue* q = (queue*)calloc(N * M + 1, sizeof(queue));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == -1) fullcount--;
			else if (a[i][j] == 1) {
				back++;
				q[back].n = i;
				q[back].m = j;
				q[back].day = 0;
			}
		}
	}//초기 토마토 위치 큐에 넣기

	BFS(a, q, q[0].n, q[0].m);

	if (fullcount != back) printf("-1");
	else printf("%d", q[back].day);

	for (int i = 0; i < N; i++) { free(a[i]); }
	free(a);
	return 0;
}

void BFS(int** a, queue* q, int y, int x) {
	while (front < back) {
		front++;
		for (int j = 0; j < 4; j++) {
			int nx = q[front].m + dx[j];
			int ny = q[front].n + dy[j];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			else {
				if (a[ny][nx] == 0) {
					back++;
					q[back].m = nx;
					q[back].n = ny;
					q[back].day = q[front].day + 1;
					a[ny][nx] = 1;
				}//토마토 익히고 큐에 추가
			}
		}
	}
}
