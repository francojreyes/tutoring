#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node *Node;

struct node *listAppend(struct node *head, int data);
void printList(struct node *node);
void freeList(struct node *head);

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

// Appends a node to the end of the list
struct node *listAppend(struct node *head, int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node *lastNode = head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }

    return head;
}

// Prints the list
void printList(struct node *node) {
    while (node->next != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("%d\n", node->data);
    return;
}

// Frees the list
void freeList(struct node *head) {
    if (head == NULL) {
        return;
    }

    // Iterate through and free all nodes
    struct node *toDelete = head;
    while (head != NULL) {
        toDelete = head;
        head = head->next;
        free(toDelete);
    }
}