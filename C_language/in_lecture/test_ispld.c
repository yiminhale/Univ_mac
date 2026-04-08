#include <stdio.h>

// 원본 (버그 있음)
int ispld_original(int i) {
	int result = 0;
	int temp,diff;
	for (temp = i / 10 ; temp != 0; temp = temp / 10) {
		int r = i - temp * 10;
		result = result * 10 + r;
	}
	if (i == result) {
		return 1;
	}
	else {
		return 0;
	}
}

// 수정본 1: 가장 사람이 짜기 쉬운 버전
int ispld_v1(int i) {
	int original = i;  // 원본 저장
	int reversed = 0;  // 뒤집은 수

	while (i > 0) {
		int digit = i % 10;        // 마지막 자릿수 추출
		reversed = reversed * 10 + digit;  // 뒤집은 수에 추가
		i = i / 10;                // 마지막 자릿수 제거
	}

	return (original == reversed) ? 1 : 0;
}

// 수정본 2: 더 간결한 버전
int ispld_v2(int i) {
	int original = i, reversed = 0;
	while (i > 0) {
		reversed = reversed * 10 + i % 10;
		i /= 10;
	}
	return original == reversed;
}

int main() {
	int test_cases[] = {1, 7, 11, 121, 123, 707, 1221, 10201, 12321, 12345};
	int num_tests = 10;

	printf("=== 회문(Palindrome) 판별 테스트 ===\n\n");
	printf("숫자\t원본\tv1\tv2\t예상\n");
	printf("─────────────────────────────────\n");

	for (int i = 0; i < num_tests; i++) {
		int n = test_cases[i];
		int orig = ispld_original(n);
		int v1 = ispld_v1(n);
		int v2 = ispld_v2(n);

		// 수동으로 회문인지 확인 (예상값)
		int expected = 0;
		if (n == 1 || n == 7 || n == 11 || n == 121 || n == 707 ||
		    n == 1221 || n == 10201 || n == 12321) {
			expected = 1;
		}

		printf("%d\t%d\t%d\t%d\t%d", n, orig, v1, v2, expected);

		if (orig != expected) {
			printf(" ← 원본 오류!");
		}
		printf("\n");
	}

	printf("\n\n=== 상세 분석 (1221) ===\n");
	int test = 1221;
	printf("원본 숫자: %d\n", test);
	printf("회문 판별 과정:\n");
	printf("  1221 → 마지막 자릿수 1 추출 → reversed = 1\n");
	printf("  122  → 마지막 자릿수 2 추출 → reversed = 12\n");
	printf("  12   → 마지막 자릿수 2 추출 → reversed = 122\n");
	printf("  1    → 마지막 자릿수 1 추출 → reversed = 1221\n");
	printf("  원본(1221) == 뒤집음(1221) → 회문!\n");

	return 0;
}
