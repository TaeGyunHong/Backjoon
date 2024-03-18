#include <stdio.h>
#include <math.h>

int main() {
    char S[1000001];
    scanf("%s", S);

    int count = 0;
    char prev = '\0';

    for (int i = 0; S[i] != '\0'; i++) {
        if (S[i] != prev) {
            count++;
            prev = S[i];
        }
    }

    count = ceil(count / 2);
    printf("%d\n", count);

    return 0;
}
