#include<stdio.h>
int T,A,B;
int cmmdc(int a, int b)
{
	int r=a%b;
	while(r!=0)
	{
		a=b;
		b=r;
		r=a%b;
	}
	
	
	return b;
}

int main()
{
	
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d", &T);
	for(int i=1;i<=T;++i)
	{
		
		scanf("%d%d", &A, &B);
		
		printf("%d", cmmdc(A,B));
	}
	return 0;
}
