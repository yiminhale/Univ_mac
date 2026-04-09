#include <stdio.h>

int main() {
	int i = 36;
	int sum = 0;

	printf("Analyzing i=%d:\n", i);
	printf("Divisors of 36: ");

	for (int t = 2; t <= i; t++) {
		if (i % t == 0) {
			printf("%d ", t);
		}
	}
	printf("\n\n");

	printf("Step-by-step sum:\n");
	for (int t = 2; t <= i; t++) {
		if (i % t == 0) {
			sum += t;
			printf("t=%d: sum = %d", t, sum);
			if (sum == i) {
				printf(" ← sum == i! Returns %d (but 36 is NOT prime!)", i);
			}
			printf("\n");
		}
	}

	return 0;
}
