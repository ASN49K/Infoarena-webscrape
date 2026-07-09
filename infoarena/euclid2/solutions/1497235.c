#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long gcd(long a, long b){
	return b == 0 ? a : gcd(b, a%b);
}
long gcdGreaterThanZero(long a, long b){
	return a == b ? a : (a > b ? gcdGreaterThanZero(a - b, b) : gcdGreaterThanZero(a, b - a));
}

long gcdBest(long a, long b){
	int temp;
	while (b != 0)
	{
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}

int main(){
	FILE *input = fopen("euclid2.in","r");
	FILE *output = fopen("euclid2.out","w");

	int n;
	long a, b;
	fscanf(input, "%d", &n);

	for (int i = 0; i < n; i++)
	{
		fscanf(input, "%ld %ld", &a, &b);
		fprintf(output, "%ld\n", gcdBest(a, b));
	}
	return 0;
}