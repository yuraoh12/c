#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
}Node;

void addfirst(struct Node* target, int data) {

	struct Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = target->next;
	newNode->data = data;

	target->next = newNode;

}

int main() {

	struct Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;

	addfirst(head, 10);
	addfirst(head, 20);
	addfirst(head, 30);
	addfirst(head, 40);

	struct Node* curr = head->next;
	while (curr != NULL) {
		printf("%d\n", curr->data);
		curr = curr->next;
	}

	curr = head->next;
	while (curr != NULL) {
		struct Node* next = curr->next;
		free(curr);
		curr = next;
	}

	free(head);

}