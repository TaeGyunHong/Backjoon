#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
	return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
	int n, m, cnt = 0;
	scanf("%d %d", &n, &m);

	char **name = (char**)malloc(sizeof(char*) * (n + m));
	for (int i = 0; i < n + m; i++) {
		name[i] = (char*)malloc(sizeof(char) * 21);
	}

	for (int i = 0; i < n; i++) {
		scanf("%s", name[i]);
	}

	for (int i = 0; i < m; i++) {
		scanf("%s", name[i + n]);
	}

	qsort(name, n + m, sizeof(char *), compare);

	for (int i = 0; i < n + m - 1; i++) {
		if (strcmp(name[i], name[i + 1]) == 0) {
			cnt++;
		}
	}

	printf("%d\n", cnt);

	for (int i = 0; i < n + m - 1; i++) {
		if (strcmp(name[i], name[i + 1]) == 0) {
			printf("%s\n", name[i]);
			while (i < n + m - 1 && strcmp(name[i], name[i + 1]) == 0) {
				i++;
			}
		}
	}

	for (int i = 0; i < n + m; i++) {
		free(name[i]);
	}
	free(name);

	return 0;
}
