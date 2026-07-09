#include<cstdio>
using namespace std;
int v[257],i,k,n,nr,m;
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		{scanf("%d ",&nr);
	      v[nr]++;
		}
		for(i=0;i<m;i++)
		{scanf("%d ",&nr);
	      v[nr]++;
		}
		for(i=0;i<=256;i++)
			if(v[i]>1)k++;
		printf("%d\n",k);
			for(i=0;i<=256;i++)
				if(v[i]>1)printf("%d ",i);
return 0;}
