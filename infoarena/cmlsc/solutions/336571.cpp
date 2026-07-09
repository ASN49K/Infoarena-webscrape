#include<stdio.h>
#define in "cmlsc.in"
#define out "cmlsc.out"
#define N 1050
int v[N], v1[N], pozv[N], pozv1[N], max=0, maxpoz=0, n, m, i;
int main()
	{
		freopen(in,"r",stdin);
		freopen(out,"w",stdout);
		scanf("%d %d", &n, &m);
		for(i=1;i<=n;i++)
			scanf("%d", &v[i]);
		for(i=1;i<=m;i++)
			{
				scanf("%d", &v1[i]);
				if(!pozv1[v1[i]])pozv1[v1[i]]=i;
		}
		for(i=1;i<=n;i++)
			
			if(pozv1[v[i]] && maxpoz<pozv1[v[i]]){pozv[max]=v[i];max++;maxpoz=pozv1[i];}
		printf("%d\n",max);
		for(i=0;i<max;i++)
			printf("%d ",pozv[i]);
return 0;
}			