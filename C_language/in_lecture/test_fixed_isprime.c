#include <stdio.h>

// 원본 (버그 있음)
int isPrime_original(int a) {
	int rtn_value=0;
	for (int i = a - 1;i;i--) {
		int sum = 0;
		for (int t = 2; t<=i;t++) {
			if (i%t==0) {
				sum += t;
			}
			if (sum==i) {  // ← 안쪽 루프에서 체크
				rtn_value = i;
				return rtn_value;
			}
		}
	}
	return rtn_value;
}

// 수정본 (if를 for 밖으로)
int isPrime_fixed(int a) {
	int rtn_value=0;
	for (int i = a - 1;i;i--) {
		int sum = 0;
		for (int t = 2; t<=i;t++) {
			if (i%t==0) {
				sum += t;
			}
		}
		if (sum==i) {  // ← 바깥 루프로 이동
			rtn_value = i;
			return rtn_value;
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

void analyze_number(int n) {
	printf("\n=== %d의 약수 분석 ===\n", n);
	int sum = 0;
	printf("약수(t=2~%d): ", n);
	for (int t = 2; t <= n; t++) {
		if (n % t == 0) {
			printf("%d ", t);
			sum += t;
		}
	}
	printf("\n총합: %d", sum);
	if (sum == n) {
		printf(" ← sum == n! (소수임)");
	} else {
		printf(" ≠ %d (합성수)", n);
	}
	printf("\n");
}

int main() {
	printf("===== 원본 vs 수정본 비교 =====\n\n");

	// 36 주변 테스트
	printf("36 주변 케이스:\n");
	for (int a = 35; a <= 40; a++) {
		int orig = isPrime_original(a);
		int fixed = isPrime_fixed(a);

		printf("a=%d: 원본=%d, 수정=%d", a, orig, fixed);

		if (orig != fixed) {
			printf(" ← 결과 다름!");
		}

		if (fixed > 0 && !is_actually_prime(fixed)) {
			printf(" *** ERROR: %d는 소수 아님! ***", fixed);
		}
		printf("\n");
	}

	printf("\n\n===== 전체 범위 테스트 (1~1000) =====\n");
	int errors = 0;

	for (int a = 2; a <= 1000; a++) {
		int result = isPrime_fixed(a);
		if (result > 0 && !is_actually_prime(result)) {
			printf("ERROR at a=%d: isPrime_fixed(%d) = %d (NOT prime!)\n", a, a, result);
			errors++;
		}
	}

	if (errors == 0) {
		printf("✓ 모든 테스트 통과! 에러 없음.\n");
	} else {
		printf("✗ 총 %d개 에러 발견\n", errors);
	}

	// 특정 수들 상세 분석
	printf("\n\n===== 상세 분석 =====");
	analyze_number(7);   // 소수
	analyze_number(36);  // 문제였던 수
	analyze_number(6);   // 완전수

	return 0;
}
