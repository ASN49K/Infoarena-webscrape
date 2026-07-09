#include<stdio.h>
int T,A,B;
int cmmdc(int a, int b)
{
	int r=a%b;
	while(r!=0)
	{
		a=b;
		b=r;
		r=a&b;
	}
	if(b==1)
		return 0;
	else
		return b;
}

int main()
{
	
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d", &T);
	for(int i=1;i<=T;++i)
	{
		int d;
		scanf("%d%d", &A, &B);
		printf("%d%d",A,B);
		d=cmmdc(A,B);
		printf("%d", d);
	}
	return 0;
}
