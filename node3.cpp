#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;


void addFirst(Node* target, int data);
void showList(Node* target);
void freeList(Node* target);
void addLast(Node* target, int data);
void add(Node* target, int location, int data);


int main() {

	int count = 0;

	// 리스트 맨 앞에 추가하기
	struct Node* node1 = (Node*)malloc(sizeof(Node));
	node1->next = NULL;

	count = 10;
	for (int i = 1; i <= count; i++) {
		if (i % 2 == 0) {
			addFirst(node1, i);
		}
	}

	showList(node1);
	freeList(node1);

	// 리스트 맨 마지막에 추가하기
	struct Node* node2 = (Node*)malloc(sizeof(Node));
	node2->next = NULL;

	for (int j = 1; j <= count; j++) {
		if (j % 2 == 1) {
			addLast(node2, j);
		}
	}

	showList(node2);
	freeList(node2);

	// 특정 위치에 추가
	struct Node* node3 = (Node*)malloc(sizeof(Node));
	node3->next = NULL;

	count = 5;
	for (int k = 1; k <= count; k++) {
		addLast(node3, k);
	}

	showList(node3);

	add(node3, 0, 100);

	showList(node3);

	add(node3, 1, 55);
	add(node3, 5, 999);

	showList(node3);
}

void addFirst(struct Node* target, int data) {

	struct Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = target->next;

	target->next = newNode;

}

void showList(Node* target) {
	Node* curr = target->next;

	while (curr != NULL) {
		printf("%d \n", curr->data);
		curr = curr->next;
	}
}

void freeList(Node* target) {

	Node* curr = target;
	Node* next;

	while (curr != NULL) {
		next = curr->next;
		free(curr);
		curr = next;
	}
}

void addLast(Node* target, int data) {

	if (target->next == NULL) {

		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->next = NULL;

		target->next = newNode;

	}
	else {

		Node* curr = target;

		while (curr->next != NULL) {
			curr = curr->next;
		}
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->next = NULL;

		curr->next = newNode;

	}



}

void add(Node* target, int location, int data) {

	Node* curr = target;

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (location == 0) {
		newNode->next = target->next;
		target->next = newNode;
	}
	else {
		int count = 0;

		while (count != location) {

			if (count == (location - 1)) {
				newNode->next = curr->next;
				curr->next = newNode;
			}
			curr = curr->next;
			count++;

		}
	}

}