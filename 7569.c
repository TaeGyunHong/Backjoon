//BFS 알고리즘
//행 = n, y	열 = m, x 높이 = h, z
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int m, n, h, day;
} Queue;

int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

int main() {
    int M, N, H;
    scanf("%d %d %d", &M, &N, &H);

    //calloc은 메모리가 부족해서 오류남
    int*** a = (int***)malloc(sizeof(int**) * H);
    for (int i = 0; i < H; i++) {
        a[i] = (int**)malloc(sizeof(int*) * N);
        for (int j = 0; j < N; j++) {
            a[i][j] = (int*)malloc(sizeof(int) * M);
            for (int k = 0; k < M; k++) {
                scanf("%d", &a[i][j][k]);
            }
        }
    }

    //초기 익은 토마토 큐 등록
    Queue* queue = (Queue*)malloc(sizeof(Queue) * M * N * H);
    int front = 0, back = 0;
    for (int k = 0; k < H; k++) {
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < M; i++) {
                if (a[k][j][i] == 1) {
                    queue[back++] = (Queue){ i, j, k, 0 };
                }
            }
        }
    }

    //외부함수로 빼려다 오류남 나중에 확인
    //토마토 익히고 큐 등록
    int max_day = 0;
    while (front < back) {
        Queue current = queue[front++];
        max_day = current.day;

        for (int i = 0; i < 6; i++) {
            int nx = current.m + dx[i];
            int ny = current.n + dy[i];
            int nz = current.h + dz[i];

            if (nx >= 0 && ny >= 0 && nz >= 0 && nx < M && ny < N && nz < H && a[nz][ny][nx] == 0) {
                a[nz][ny][nx] = 1;
                queue[back++] = (Queue){ nx, ny, nz, current.day + 1 };
            }
        }
    }

    // 모든 토마토가 익었는지 확인
    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (a[z][y][x] == 0) {
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }

    printf("%d\n", max_day);

    // 메모리 해제
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            free(a[i][j]);
        }
        free(a[i]);
    }
    free(a);
    free(queue);

    return 0;
}
