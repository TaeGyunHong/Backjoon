#include <stdio.h>
#include <stdlib.h>

int cr[50];
int box[10000];
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(void) {
    int cr_n, box_n;
    int min_t = 0;
    int cr_index;
    int up = 0;
    
    scanf("%d", &cr_n);
    for (int i = 0; i < cr_n; i++) {
        scanf("%d", &cr[i]);
    }
    
    scanf("%d", &box_n);
    for (int i = 0; i < box_n; i++) {
        scanf("%d", &box[i]);
    }
    
    qsort(cr, cr_n, sizeof(int), compare);
    qsort(box, box_n, sizeof(int), compare);

    if (box[box_n - 1] > cr[cr_n - 1]) {
        printf("-1\n");
        return 0;
    }
    
    while (up != box_n) {
        min_t++;
        cr_index = cr_n - 1;
        for (int i = box_n - 1; i >= 0; i--) {
            if (box[i] == 0)
                continue;
            if (cr_index == -1)
                break;
            if (box[i] <= cr[cr_index]) {
                cr_index--;
                up++;
                box[i] = 0;
            }
        }
    }
    printf("%d\n", min_t);
    return 0;
}
