#include <stdio.h>

int gcd(int a, int b){
	if(b == 0){
		return a;
	
	}else{
		return gcd(b, a % b);
	}
}

int main(void)
{
	int a, b, T;
    
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);

    for(int i = T; i > 0; --i){
    	scanf("%d %d", &a, &b);
    	printf("%d", gcd(a,b));
    	printf("\n");
    }

    return 0;

}