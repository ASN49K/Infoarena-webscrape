#include <stdio.h> 
int t, A, B,x,y; 
int euc(int a,int b)
{
	int c,d;
	if(a<b)
	{
		c=a;
		a=b;
		b=c;
	}
	while(b)
	{
		d=a%b;
		a=b;
		b=d;
	}
	return a;
}
int main(void) 
{ 
	freopen("euclid2.in", "r", stdin); 
	freopen("euclid2.out", "w", stdout);  
	scanf("%d", &t); 
	while(t--) 
	{ 
		scanf("%d %d", &A, &B); 
		y=euc(A,B);
		printf("%d\n", y); 
	}         
}