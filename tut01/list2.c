struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
};

int listLength(struct list *list) {
    int size = 0;
    for (struct node *curr = list->head; curr != NULL; curr = curr->next) {
        size++;
    }
    return size;
}
