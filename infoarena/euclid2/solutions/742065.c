#include <stdio.h>

int gcd(int a, int b){
	int t;
	if (a < b){ 
		return gcd(b, a);
	}
	while(b){
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main(){
	int a, b, nr, i;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	scanf("%d", &nr);
	for(i = 0; i < nr; i++){
		scanf("%d %d", &a,  &b);
		printf("%d\n", cmmdc(a, b));
	}
	return 0;
}
