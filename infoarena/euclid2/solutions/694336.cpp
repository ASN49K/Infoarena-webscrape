#include <stdio.h>
int fun(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	return fun(b,a%b);
}
int main()
{
	int N,A,B;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&N);
	for(;N;N--)
    {
		scanf("%d %d",&A,&B);
		printf("%d\n",fun(A,B));
	}
}
	