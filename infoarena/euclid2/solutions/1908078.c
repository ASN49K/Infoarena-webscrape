#include <stdio.h>


long euclid(int a, int b){
	if (b==0) return a;
	else return euclid(b, a%b);
}

int main(){

	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	
	long t;
	long a, b;
	int i;
	
	scanf("%l\n", &t);
	for (i = 0; i<t; i++){
		scanf("%l %l", a, b);
		printf("%l\n", euclid(a, b));
	}
		
	return 0;
}
