#include<stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node* next;
	struct node* front;
};

struct bucket {
	int count;
	struct node* head;
	struct node* tail;
};

struct bucket* hashTable = NULL;

struct node* createNode(int key) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->num = key;
	newNode->next = NULL;
	newNode->front = NULL;
	return newNode;
}

void insert(int key) {
	struct node* newNode = createNode(key);
	if (hashTable->count == 0) {
		hashTable->head = newNode;
		hashTable->tail = newNode;
		hashTable->count = 1;
	}
	else {
		newNode->front = hashTable->tail;
		hashTable->tail->next = newNode;
		hashTable->tail = newNode;
		hashTable->count++;
	}
}

void remover(int flag) {
	struct node* node = NULL;
	if (flag) {
		node = hashTable->head;
		hashTable->head = node->next;
		if (hashTable->head != NULL) hashTable->head->front = NULL;
	}
	else {
		node = hashTable->tail;
		hashTable->tail = node->front;
		if (hashTable->tail != NULL) hashTable->tail->next = NULL;
	}
	hashTable->count--;
	free(node);
}

void display(int flag) {
	struct node* horse = NULL;
	if (!hashTable->count) {
		printf("[]\n");
		return;
	}
	if (flag) {
		horse = hashTable->head;
		printf("[%d", horse->num);
		horse = horse->next;
		while (horse != NULL) {
			printf(",%d", horse->num);
			horse = horse->next;
		}
		printf("]\n");
	}
	else {
		horse = hashTable->tail;
		printf("[%d", horse->num);
		horse = horse->front;
		while (horse != NULL) {
			printf(",%d", horse->num);
			horse = horse->front;
		}
		printf("]\n");
	}
}

void node_free() {
	struct node* horse = hashTable->head;
	while (hashTable->count) {
		struct node* node = horse->next;
		free(horse);
		horse = node;
		hashTable->count--;
	}
}

int main() {
	int T, n, x, str_index, flag, error;
	char str[100001], str_temp;
	hashTable = (struct bucket*)malloc(sizeof(struct bucket));
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		hashTable->count = 0;
		hashTable->head = NULL;
		hashTable->tail = NULL;
		str_index = 0, flag = 1, error = 0;
		scanf("%s %d", str, &n);
		scanf(" %c", &str_temp);
		if (n) {
			for (int j = 0; j < n; j++) {
				scanf("%d %c", &x, &str_temp);
				insert(x);
			}
		}
		else scanf(" %c", &str_temp);
		for (int j = 0; str[j] != '\0'; j++) {
			if (str[j] == 'R') flag = (flag + 1) % 2;
			else {
				if (!hashTable->count) {
					error++;
					break;
				}
				remover(flag);
			}
		}
		if (error) printf("error\n");
		else display(flag);
		node_free();
	}
	free(hashTable);
}
