
int pow(int x, unsigned int n);

int main(void) {
    int n, x;
    scanf("%d %d", &n, &x);
    printf("%d^%d = %d\n", x, n, pow(x, n));
}

int pow(int x, unsigned int n) {
	int res = 1;
	for (int i = 1; i <= n; i++) {
		res = res * x;
	}
	return res;
}