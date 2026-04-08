#include <stdio.h>

int isPrime_original(int a) {
	int rtn_value=0;
	for (int i = a - 1;i;i--) {
		int sum = 0;
		for (int t = 2; t<=i;t++) {
			if (i%t==0) {
				sum += t;
			}
			if (sum==i) {
				rtn_value = i;
				return rtn_value;
			}
		}
	}
	return rtn_value;
}

int is_actually_prime(int n) {
	if (n <= 1) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

void analyze_number(int n) {
	printf("\n=== Analyzing %d ===\n", n);
	printf("Divisors: ");
	int sum = 0;
	for (int t = 2; t <= n; t++) {
		if (n % t == 0) {
			printf("%d ", t);
			sum += t;
			if (sum == n) {
				printf("\n→ Sum up to %d = %d (partial sum equals n!)\n", t, sum);
				return;
			}
		}
	}
	printf("\n");
}

int main() {
	printf("Finding all edge cases up to 1000...\n\n");

	int edge_cases[100];
	int count = 0;

	for (int a = 2; a <= 1000; a++) {
		int result = isPrime_original(a);
		if (result > 0 && !is_actually_prime(result)) {
			edge_cases[count++] = result;
			printf("ERROR: isPrime(%d) = %d (NOT prime!)\n", a, result);
		}
	}

	printf("\n\nTotal edge cases found: %d\n", count);
	printf("Unique edge case numbers: ");

	// 중복 제거
	for (int i = 0; i < count; i++) {
		int unique = 1;
		for (int j = 0; j < i; j++) {
			if (edge_cases[i] == edge_cases[j]) {
				unique = 0;
				break;
			}
		}
		if (unique) {
			printf("%d ", edge_cases[i]);
		}
	}

	// 상세 분석
	printf("\n\nDetailed analysis:");
	analyze_number(36);
	if (count > 1) {
		// 다른 엣지케이스도 분석
		for (int i = 0; i < count; i++) {
			int unique = 1;
			for (int j = 0; j < i; j++) {
				if (edge_cases[i] == edge_cases[j]) {
					unique = 0;
					break;
				}
			}
			if (unique && edge_cases[i] != 36) {
				analyze_number(edge_cases[i]);
			}
		}
	}

	return 0;
}
