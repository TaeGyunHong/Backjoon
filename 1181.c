#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char a[20000][51];

int compare(const char* b, const char* c) {
	return strlen(b) > strlen(c) ? 1 : (strlen(b) < strlen(c)) ? -1 : strcmp(b, c);
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", &a[i]);
	}

	qsort(a, N, sizeof(char) * 51, compare);

	printf("%s\n", a[0]);
	for (int j = 1; j < N; j++) {
		if (strcmp(a[j - 1], a[j]) != 0) {
			printf("%s\n", a[j]);
		}
	}
}
