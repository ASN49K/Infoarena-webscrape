//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//
//int euclid(int n, int m) {
//	int c;
//	if (m > n) {
//		while (n) {
//			c = m % n;
//			m = n;
//			n = c;
//		}
//		return m;
//	}
//	else {
//		while (m) {
//			c = n % m;
//			n = m;
//			m = c;
//		}
//	}
//	return n;
//}
//
//int main() {
//	FILE* f = fopen("euclid2.in.txt", "r");
//	FILE* g = fopen("euclid2.out.txt", "w");
//	int a, n , m ;
//	fscanf(f, "%d", &a);
//	
//	for (int i = 0; i < a; i++) {
//		fscanf(f, "%d", &n);
//		fscanf(f, "%d", &m);
//		fprintf(g, "%d\n", euclid(n, m));
//		
//	}
//
//	fclose(f);
//	fclose(g);
//
//	return 0;
//}