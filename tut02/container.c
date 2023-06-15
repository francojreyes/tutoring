#include <stdlib.h>

struct list {
    struct node *head;
};

struct node {
	int data;
	struct node *next;
};

int doListLength(struct node *head) {
    if (head == NULL) {
        return 0;
    } else {
        return 1 + listLength(head->next);
    }
}

int listLength(struct list *l) {
    return doListLength(l->head);
}