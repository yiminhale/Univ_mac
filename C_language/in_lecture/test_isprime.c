#include <stdio.h>

// 원본 함수
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

// 표준 소수 판별
int is_actually_prime(int n) {
	if (n <= 1) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	printf("Testing isPrime function for edge cases...\n\n");

	// 100까지의 모든 수 테스트
	for (int a = 2; a <= 100; a++) {
		int result = isPrime_original(a);

		// result가 실제로 소수인지 확인
		if (result > 0) {
			int is_prime = is_actually_prime(result);
			printf("isPrime(%d) = %d", a, result);
			if (!is_prime) {
				printf(" *** ERROR! %d is NOT prime! ***", result);
			}
			printf("\n");
		}
	}

	printf("\n\nDetailed check for specific cases:\n");

	// 특정 케이스들 상세 분석
	int test_cases[] = {6, 7, 8, 9, 10, 12, 15, 20, 28, 30};
	for (int i = 0; i < 10; i++) {
		int n = test_cases[i];
		int result = isPrime_original(n);
		printf("isPrime(%d) = %d (expected: ", n, result);

		// n-1부터 역순으로 실제 소수 찾기
		int expected = 0;
		for (int j = n - 1; j >= 2; j--) {
			if (is_actually_prime(j)) {
				expected = j;
				break;
			}
		}
		printf("%d) %s\n", expected, result == expected ? "✓" : "✗");
	}

	return 0;
}
