#include <cstdio>
int v[1025],bf[1025],comm[1025];
int main()
{
	int n,m,i,x,j,max,poz;
	
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (i=1;i<=n;++i) scanf("%d",&v[i]);
	for (i=1;i<=m;++i)  
	{
		scanf("%d",&x);
		max=0;
		for (j=1;j<=n;++j)
			{
				if (x==v[j]) ++comm[j];
				if (comm[j]>max) max=comm[j],poz=j;
				if (max>comm[j]) comm[j]=max,bf[j]=poz;
			}
	}
	for (i=1,max=0;i<=n;++i) 
		if (comm[i]>max)
			max=comm[i],poz=i;
	printf("%d\n",max);
	j=max;
	while (max!=0)
	{
		comm[max]=v[poz];
		poz=bf[poz];
		--max;
	}
	for (i=1;i<=j;++i) printf("%d ",comm[i]);
return 0;
}
	
		
				
		