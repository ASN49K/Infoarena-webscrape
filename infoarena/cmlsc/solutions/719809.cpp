#include<stdio.h>
int  l[100000]={0},t[100000]={0};
int n,m;
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	scanf("%d%d",&n,&m);

	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		l[a]=i+1;
	}
	int v=0,k=0;
	for(int i=0;i<m;i++)
	{
		int a;
		scanf("%d",&a);
		if(l[a] && l[a]>v)
		{
			//printf("%d",a);
			t[k]=a;
			v=l[a];
			k++;
		}
	}
	printf("%d\n",k);
	for(int i=0;i<k;i++)
		printf("%d ",t[i]);
	return 0;
}
