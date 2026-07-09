#include<stdio.h>


int euclid(int x,int y)
{
	if(!y) return x;
	else return euclid(y,x%y);
}

int main()
{
	int n;
	freopen ("euclid2.in","r",stdin);
	freopen ("euclid2.out","w",stdout);

	scanf("%d",&n);

	int x,y;

	for(int i=1; i<=n; i++)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",euclid(x,y));
	}
}

