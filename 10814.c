#include <stdio.h>
#include <stdlib.h>

struct Member{
    int age;
    char name[101];
};

int compare(const void* arg1, const void* arg2) {
    struct Member *a = (struct Member*)arg1;
    struct Member *b = (struct Member*)arg2;
    if (a->age > b->age) return 1;
    else if (a->age < b->age) return -1;
    else return 0;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    struct Member* members = (struct Member*)malloc(sizeof(struct Member) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d%*c%s", &members[i].age, members[i].name);
    }
    qsort(members, N, sizeof(struct Member), compare);

    for (int i = 0; i < N; i++) {
        printf("%d %s\n", members[i].age, members[i].name);
    }
    free(members);
    return 0;
}
