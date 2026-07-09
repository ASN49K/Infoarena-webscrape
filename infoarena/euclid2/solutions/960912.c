#include <stdio.h>

int gcdfast ( int a, int b ){
	if (!b) return a;
	return  gcdfast( b , a % b );
}

int gcdslow ( int a , int b  ){
	if (!a) return b;
	if (a < b) { int t = a; a = b ; b = t; }
	gcdslow(a - b, b);
}

int main(){
	int T,A,B;
	FILE * in, *out;

	freopen ("euclid2.in", "r" ,stdin);
	freopen ("euclid2.out", "w", stdout);
	scanf ("%d", &T);
	
	for (; T; --T){
		scanf("%d %d", &A, &B);
		printf ( "%d\n", gcdfast(A,B));
	}
	
	return 0;
}
