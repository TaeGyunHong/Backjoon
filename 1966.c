#include <stdio.h>

int main() {
	int count, num, m, a[100] = { 0, };
	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf("%d %d", &num, &m);
		for (int j = 0; j < num; j++) scanf("%d", &a[j]);

		int front = 0, max = 0, result = 1;
		while (1) {
			for (int k = 0; k < num; k++) {
				if (a[k] > max) max = a[k];
			}
			while (a[front] != max) front = (front + 1) % num;
			if (front == m) break;

			a[front] = 0;
			front = (front + 1) % num;
			max = 0;
			result++;
		}
		printf("%d\n", result);
	}
}
