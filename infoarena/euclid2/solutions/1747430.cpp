#include <stdio.h>

int gcd(int a, int b){
	if(a == 0){
		return b;
	}
	return gcd(b%a, a);
}

int main(){

	freopen("euclid2.in","r", stdin);
	freopen("euclid2.out","w", stdout);
	
	int number, nr1, nr2;
	scanf("%d", &number);
	while(number--) {
		scanf("%d %d", &nr1, &nr2);
		printf("%d\n", gcd(nr1, nr2));
	}
		
	return 0;
}
	