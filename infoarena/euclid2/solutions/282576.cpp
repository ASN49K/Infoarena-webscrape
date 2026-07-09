#include<stdio.h>
int T;
int euclid(int a,int b)
	{
	if(!b)return a;
	return euclid(b,a%b);
	}

int main()
	{int i,x,y;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
	scanf("%d %d",&x,&y);
	printf("%d\n",euclid(x,y));
	}
	return 0;
	}
