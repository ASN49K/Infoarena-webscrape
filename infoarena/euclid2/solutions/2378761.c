#include<stdio.h>

int main(){
	int n;
	long a, b, c;
	freopen("euclid2.in", "r", stdin);   
    	freopen("euclid2.out", "w", stdout);   
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%li %li", &a, &b);
		if(a % b == 0)
			printf("%li\n", b);
		else if(b % a == 0)
			printf("%li\n", a);
		else{
			while(a % b){
				c = a;
				a = b;
				b = c % b;
			}
			printf("%li\n", b);
		}
	}
	return 0;
}
