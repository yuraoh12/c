#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

// 1 -> 2 -> 3 -> 4 -> null

int main() {

	// head 생성
	struct Node* head = (Node*)malloc(sizeof(Node));

	// 첫 번째 노드 생성
	struct Node* node1 = (Node*)malloc(sizeof(Node));
	head->next = node1;
	node1->data = 1;

	struct Node* node2 = (Node*)malloc(sizeof(Node));
	node1->next = node2;
	node2->data = 2;

	struct Node* node3 = (Node*)malloc(sizeof(Node));
	node2->next = node3;
	node3->data = 3;

	struct Node* node4 = (Node*)malloc(sizeof(Node));
	node3->next = node4;
	node4->data = 4;

	node4->next = NULL;

	struct Node* curr = head->next;
	while (curr != NULL) {

		printf("%d\n", curr->data);
		curr = curr->next;
	}

	free(node4);
	free(node3);
	free(node2);
	free(node1);

	free(head);
}