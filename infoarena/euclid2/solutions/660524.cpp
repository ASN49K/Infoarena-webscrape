#include <stdio.h>   
  
int T, A, B;   
  
int gcd(int a, int b)   
{
	while (a!=b)
		if (a>b)
		{
			a=a%b;
		}
		else
		{
			b=b%a;
		}
		
	return a;

}   
  
int main()   
{   
    freopen("euclid2.in", "r", stdin);   
    freopen("euclid2.out", "w", stdout);   
  
    scanf("%d", &T);   
    for (; T; --T)   
    {   
        scanf("%d %d", &A, &B);   
        printf("%d\n", gcd(A, B));   
    }           
  
    return 0;   
} 