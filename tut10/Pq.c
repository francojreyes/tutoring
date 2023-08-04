// Implementation of a priority queue of integers
// Uses a min-heap

// !!! DO NOT MODIFY THIS FILE !!!

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Pq.h"

#define DEFAULT_CAPACITY 64

struct pq {
	int *items;
	int size;
	int capacity;
};

static void fixUp(Pq pq, int i);
static void fixDown(Pq pq, int i);
static void swap(int *items, int i, int j);

Pq PqNew(void) {
	Pq pq = malloc(sizeof(*pq));
	if (pq == NULL) {
		fprintf(stderr, "Couldn't allocate Pq!\n");
		exit(EXIT_FAILURE);
	}
	
	pq->items = malloc((DEFAULT_CAPACITY + 1) * sizeof(int));
	if (pq->items == NULL) {
		fprintf(stderr, "Couldn't allocate Pq!\n");
		exit(EXIT_FAILURE);
	}
	
	pq->size = 0;
	pq->capacity = DEFAULT_CAPACITY;
	return pq;
}

void PqFree(Pq pq) {
	free(pq->items);
	free(pq);
}

void PqInsert(Pq pq, int e) {
	// If the Pq is full, expand it (i.e., double its capacity)
	if (pq->size == pq->capacity) {
		pq->capacity *= 2;
		pq->items = realloc(
			pq->items,
			(pq->capacity + 1) * sizeof(int)
		);
		if (pq->items == NULL) {
			fprintf(stderr, "Couldn't expand Pq!\n");
			exit(EXIT_FAILURE);
		}
	}
	
	// Add the new item to the end
	pq->size++;
	pq->items[pq->size] = e;
	fixUp(pq, pq->size);
}

static void fixUp(Pq pq, int i) {
	while (i > 1 && pq->items[i] < pq->items[i / 2]) {
		swap(pq->items, i, i / 2);
		i = i / 2;
	}
}

int PqExtract(Pq pq) {
	assert(pq->size > 0);
	
	int e = pq->items[1];
	pq->items[1] = pq->items[pq->size];
	pq->size--;
	fixDown(pq, 1);
	return e;
}

static void fixDown(Pq pq, int i) {
	int *es = pq->items;
	while (true) {
		int j = i;
		int l = 2 * i;
		int r = 2 * i + 1;
		if (l <= pq->size && es[l] < es[j]) j = l;
		if (r <= pq->size && es[r] < es[j]) j = r;
		if (j == i) break;
		swap(pq->items, i, j);
		i = j;
	}
}

int PqSize(Pq pq) {
    return pq->size;
}

bool PqIsEmpty(Pq pq) {
	return (pq->size == 0);
}

void PqShow(Pq pq) {
	printf("#items = %d\n", pq->size);
	printf("Items:");
	for (int i = 1; i <= pq->size; i++) {
		printf(" %d", pq->items[i]);
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////////

static void swap(int *items, int i, int j) {
	int tmp = items[i];
	items[i] = items[j];
	items[j] = tmp;
}
