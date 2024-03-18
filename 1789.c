//범위를 맞추기 위해 long long 사용 미사용시 예외발생
#include <stdio.h>

int main() {
    long long int S, N = 0;
    scanf("%d", &S);
    
    int i = 1;
    while(1) {
        S -= i;
        if (S < 0) break;
        i++;
        N++;
    }
    printf("%d", N);
}
