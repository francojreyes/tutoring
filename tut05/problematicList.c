#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
typedef struct node *Node;

// Frees the list
void freeList(struct node *head) {
	if (head == NULL) {
		return;
	}

	struct node *temp = head;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

// Prints out the list separated by ->
void printList(struct node *head) {
	while (head->next != NULL) {
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("%d\n", head->data);
}

// Append a node to the end of the list
struct node *listAppend(struct node *head, int data) {
	struct node *newNode = malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL) {
		// Empty list
		head = newNode;
	} else {
		// Non-empty list
		// Loop through and find last node
		struct node *lastNode = head;
		while (lastNode->next != NULL) {
			lastNode = lastNode->next;
		}
		lastNode->next = newNode;
	}
	return head;
}

int main() {
	struct node *head = NULL;
	head = listAppend(head, 1);
	head = listAppend(head, 2);
	head = listAppend(head, 3);
	head = listAppend(head, 4);
	printList(head);
	freeList(head);
	return 0;
}
