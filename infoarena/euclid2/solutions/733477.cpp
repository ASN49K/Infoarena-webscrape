#include<stdio.h>
int
int main ()
{
	freopen("ciur.in","r",stdin);
	freopen("ciur.out","w",stdout);
	scanf("%d",&x);
	for(i=1;i<=x;i++)
	{
		if(v[i]==0)
		{
			for(j=2;j<=x/i;j++)
			{
				v[j*i]=1;
			}
		}
	}
	for(i=1;i<=x;i++)
	{
		if(!v[i])
			nr++;
	}
	printf("%d",nr);
	return 0;
}