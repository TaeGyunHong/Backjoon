//그리디 알고리즘, 정렬
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

int compare(const void* a, const void* b) {
    Meeting m1 = *(Meeting*)a;
    Meeting m2 = *(Meeting*)b;

    if (m1.end > m2.end)
        return 1;
    else if (m1.end == m2.end) {
        if (m1.start > m2.start)
            return 1;
        else
            return -1;
    }
    else
        return -1;
}

int main() {
    int N;
    scanf("%d", &N);
    Meeting meetings[N];

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }
    qsort(meetings, N, sizeof(Meeting), compare);

    int count = 1;
    int lastEndTime = meetings[0].end;
    for (int i = 1; i < N; i++) {
        if (meetings[i].start >= lastEndTime) {
            count++;
            lastEndTime = meetings[i].end;
        }
    }

    printf("%d\n", count);
}
