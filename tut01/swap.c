#include <stdio.h>

void swap(int *pa, int *pb);

int main(void) {
	int a = 5;
	int b = 7;
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);
}

void swap(int *pa, int *pb) {
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
