#include "stdlib.h"

struct node {
    int value;
    struct node *next;
};

int main(void) {
	struct node *n = malloc(sizeof(struct node));
	(*n).value = 42;
	n->value = 42;
	n->next = NULL;

	int stackArr[5];
	int *heapArr = malloc(/* number_of_items * sizeof(type_of_item) */);
	             = malloc(5 * sizeof(int));

	// sizeof(8) == sizeof(int) == 4;
//	struct node *n2 = malloc(sizeof(*n2));
}

int listLength(struct node *list) {
    return 0;
}

