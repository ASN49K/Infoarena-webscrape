#include <stdio.h>      
long a, b;      
int t;
long cmmdc(long a, long b){      
    if(b==0) return a;      
    return cmmdc(b, a%b);   
}   
int main()      
{      
    freopen("euclid2.in", "r", stdin);      
    freopen("euclid2.out", "w", stdout);   
	scanf("%d", &t);
	for(int i=1; i<=t; ++i){
    scanf("%ld %ld", &a, &b);      
    printf("%ld\n", cmmdc(a, b));
	}	
    return 0;      
}    
