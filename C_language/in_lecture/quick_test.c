#include <stdio.h>

int isPrime(int a) {
	int rtn_value=0;
	for (int i = a - 1;i;i--) {
		int sum = 0;
		for (int t = 2; t<=i;t++) {
			if (i%t==0) {
				sum += t;
			}
		}
		if (sum==i) {
			rtn_value = i;
			return rtn_value;
		}
	}
	return rtn_value;
}

int main() {
	printf("isPrime(37) = %d (기대값: 31)\n", isPrime(37));
	printf("isPrime(9) = %d (기대값: 7)\n", isPrime(9));
	printf("isPrime(10) = %d (기대값: 7)\n", isPrime(10));
	printf("isPrime(100) = %d (기대값: 97)\n", isPrime(100));
	return 0;
}
