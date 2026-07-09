#include <stdio.h>


long euclid(long a, long b){
	if (b==0) return a;
	else return euclid(b, a%b);
}

int main(){

	//freopen("euclid2.in", "r", stdin);
	//2freopen("euclid2.out", "w", stdout);
	
	long t;
	long a, b;
	int i;
	
	scanf("%ld", &t);
	for (i = 0; i<t; i++){
		scanf("%ld %ld", &a, &b);
		printf("%ld\n", euclid(a, b));
	}
		
	return 0;
}
