#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long long dec2bin(int dec) {
	int power;
	for (power = 0; ; power++) {
		if (pow(2, power) >= dec) {
			break;
		}
	}
	long long bin = 0;
	int p;
	for (; dec; power--) {
		p = pow(2, power);
		if (dec >= p) {
			dec -= p;
			bin += pow(10, power);
		}
	}
	return bin;
}

long long dec2bin_fast(int dec) {
	long long bin = 0;
	for (int power = 0; dec > 0; power++) {
		if (dec & 1) {
			bin += pow(10, power);
		}
		dec = dec >> 1;
		printf("%d\n", dec);
	}
	return bin;
}

int main() {
	char input[128];
	int dec;
	while (fgets(input, 128, stdin) != NULL) {
		dec = atoi(input);
		#ifdef FAST
		printf("%lld, ", dec2bin_fast(dec));
		#else
		printf("%lld, ", dec2bin(dec));
		#endif
	}
}
