#include <stdio.h>   
  
int T, A, B;   
  
int gcd(int a, int b)   
{
		do 
		if (a>b)
		{
			a=a-b;
		}
		else
		{
			b=b-a;
		}
		while (a!=b)
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