//bfs
//큐 동적할당 > 런타임 에러
#include <stdio.h>
#include <stdlib.h>

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

typedef struct Node {
	int x;
	int y;
	int distance;
} Node;
Node queue[100 * 100];

int bfs(int** maze, int n, int m) {
	int front = 0, rear = 0;
  //Node* queue = (Node*)malloc(sizeof(Node) * n * m);
	queue[rear++] = (Node) { 0, 0, 1 };

	while (front < rear) {
		Node current = queue[front++];

		if (current.x == n - 1 && current.y == m - 1) {
      //free(queue);
      return current.distance;
    }

		for (int i = 0; i < 4; i++) {
			int nx = current.x + dx[i];
			int ny = current.y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == 1) {
				queue[rear++] = (Node) { nx, ny, current.distance + 1 };
				maze[nx][ny] = 0;
			}
		}
	}
  //free(queue);
	return -1;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int** maze = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		maze[i] = (int*)malloc(sizeof(int) * m);
		for (int j = 0; j < m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}

	int result = bfs(maze, n, m);
	printf("%d\n", result);

	for (int i = 0; i < n; i++) {
		free(maze[i]);
	}
	free(maze);
}
