#include <stdio.h>   
long a, b;   
long cmmdc(long a, long b){   
	if(b==0) return a;   
	return cmmdc(b, a%b);
}
int main()   
{   
    freopen("euclid2.in", "r", stdin);   
    freopen("euclid2.out", "w", stdout);   
	scanf("%ld %ld", &a, &b);   
    printf("%ld\n", cmmdc(a, b));   
    return 0;   
}  
