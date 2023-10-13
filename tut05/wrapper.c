#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////
// Plain linked list

struct listNode {
    int value;
    struct listNode *next;
};

struct listNode *listAppend(struct listNode *n, int val);
int listSize(struct listNode *n);

void runList(void) {
    struct listNode *l = NULL;
    l = listAppend(l, 1);
    l = listAppend(l, 2);
    l = listAppend(l, 3);

    printf("%d\n", listSize(l));
}

struct listNode *listAppend(struct listNode *n, int val) {
    if (n == NULL) {
        n = malloc(sizeof(*n));
        n->value = val;
        n->next = NULL;
    } else {
        n->next = listAppend(n->next, val);
    }
    return n;
}

int listSize(struct listNode *n) {
    if (n == NULL) {
        return 0;
    } else {
        return listSize(n->next) + 1;
    }
}

/////////////////////////////////////////////////////////////////////
// Linked list wrapper

struct listW {
    struct listWNode *head;
    int size;
    struct listWNode *tail;
};

struct listWNode {
    int value;
    struct listWNode *next;
};

struct listW *listWNew(void);
void listWAppend(struct listW *l, int val);
int listWSize(struct listW *l);

void runListW(void) {
    struct listW *l = listWNew();
    listWAppend(l, 1);
    listWAppend(l, 2);
    listWAppend(l, 3);

    printf("%d\n", listWSize(l));
}

struct listW *listWNew(void) {
    struct listW *l = malloc(sizeof(*l));
    l->head = NULL;
    l->size = 0;
    l->tail = NULL;
    return l;
}

void listWAppend(struct listW *l, int val) {
    struct listWNode *n = malloc(sizeof(*n));
    n->value = val;
    n->next = NULL;
    if (l->tail == NULL) {
        l->head = l->tail = n;
    } else {
        l->tail->next = n;
        l->tail = n;
    }
    l->size++;
}

int listWSize(struct listW *l) {
   return l->size;
}

/////////////////////////////////////////////////////////////////////
// Plain BST

struct bstNode {
    int value;
    struct bstNode *left;
    struct bstNode *right;
};

struct bstNode *bstInsert(struct bstNode *n, int val);
int bstSize(struct bstNode *n);

void runBst(void) {
    struct bstNode *t = NULL;
    t = bstInsert(t, 1);
    t = bstInsert(t, 2);
    t = bstInsert(t, 3);

    printf("%d\n", bstSize(t));
}

struct bstNode *bstInsert(struct bstNode *n, int val) {
    if (n == NULL) {
        n = malloc(sizeof(*n));
        n->value = val;
        n->left = n->right = NULL;
    } else if (val < n->value) {
        n->left = bstInsert(n->left, val);
    } else if (val > n->value) {
        n->right = bstInsert(n->right, val);
    }
    return n;
}

int bstSize(struct bstNode *n) {
    if (n == NULL) {
        return 0;
    } else {
        return bstSize(n->left) + bstSize(n->right) + 1;
    }
}

/////////////////////////////////////////////////////////////////////
// BST wrapper

struct bstW {
    struct bstWNode *root;
};

struct bstWNode {
    int value;
    struct bstWNode *left;
    struct bstWNode *right;
};

struct bstW *bstWNew(void);
void bstWInsert(struct bstW *t, int val);
int bstWSize(struct bstW *t);

void runBstW(void) {
    struct bstw *t = bstWNew();
    bstWInsert(t, 1);
    bstWInsert(t, 2);
    bstWInsert(t, 3);
}

struct bstW *bstWNew(void) {
    struct bstW *t = malloc(sizeof(*t));
    t->root = NULL;
    return t;
}

struct bstWNode *doBstWInsert(struct bstWNode *n, int val) {
    if (n == NULL) {
        n = malloc(sizeof(*n));
        n->value = val;
        n->left = n->right = NULL;
    } else if (val < n->value) {
        n->left = doBstWInsert(n->left, val);
    } else if (val > n->value) {
        n->right = doBstWInsert(n->right, val);
    }
    return n;
}

void bstWInsert(struct bstW *t, int val) {
    t->root = doBstWInsert(t->root, val);
}

int bstWSize(struct bstW *t) {
    return 0;
}


/////////////////////////////////////////////////////////////////////
// An ADT

struct set {

};

typedef struct set *Set;

Set SetNew();
void SetInsert(Set s, int val);

/////////////////////////////////////////////////////////////////////

int main(void) {
    runList();
    runListW();
    runBst();
    runBstW();
}
