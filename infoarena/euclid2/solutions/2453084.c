#include<stdio.h>

int euclid(int a, int b) {

	int c;
	while (b) {
		c = a%b;
		a = b;
		b = c;
	}
	return a;
}
int main() {

	int a, b, t,i;
	FILE *fin,*fout;
	fin = fopen("euclid2.in", "a + t");
	fout = fopen("euclid2.out", "a+t");

	fscanf(fin, "%d ", &t);

	for (i = 0; i < t; i++) {
		fscanf(fin, "%d %d", &a, &b);
		
		fprintf(fout, "%d \n", euclid(a, b));
	}




	return 0;
}