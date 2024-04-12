#include <stdio.h>
 
int main() {
 
    int a, b;
    int mul1 = 1, mul2 = 1, mul3 = 1;
    scanf("%d %d", &a, &b);
 
    for (int i = 1; i <= a; i++) {
        mul1 *= i;
    }
    for (int j = 1; j <= b; j++) {
        mul2 *= j;
    }
    for (int k = 1; k <= a - b; k++) {
        mul3 *= k;
    }
 
    printf("%d", mul1 / (mul2 * mul3));
}
