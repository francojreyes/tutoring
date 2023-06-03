struct node {
    int value;
    struct node *next;
};

int listLength(struct node *list) {
    int size = 0;
    for (struct node *curr = list; curr != NULL; curr = curr->next) {
        size++;
    }
    return size;
}

