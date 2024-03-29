//dfs
#include <stdio.h>
#include <stdlib.h>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int x[500] = {0}, y = 0;

void dfs(int **a, int p, int q, int n) {
    a[p][q] = 0;
    x[y]++;
    for (int i = 0; i < 4; i++) {
        int nx = p + dx[i];
        int ny = q + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
            if (a[nx][ny] == 1) dfs(a, nx, ny, n);
        }
    }
}

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int **a = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++) {
        a[i] = (int *)calloc(n, sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        char line[25 + 1];
        scanf("%s", line);
        for (int j = 0; j < n; j++) {
            a[i][j] = line[j] - '0';
        }
    }

    int com = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                dfs(a, i, j, n);
                com++;
                y++;
            }
        }
    }

    qsort(x, y, sizeof(int), cmp);
    
    printf("%d\n", com);
    for (int i = 0; i < y; i++) {
        printf("%d\n", x[i]);
    }

    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
}
