#include<cstdio>
int x,y,i,N;
int cmmdc(int x,int y)
{
	if(x==y)
		return x;
	else
		if(x>y)
			return cmmdc(x-y,y);
		else
			return cmmdc(x,y-x);
}
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",cmmdc(x,y));
	}
	return 0;
}
