#include<stdio.h>
int n1,n2,i,nr,v1[1050],v2[1050],v[1050],f2[300];
int main()
{
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d%d",&n1,&n2);
for(i=1;i<=n1;i++)
	scanf("%d",&v1[i]);
for(i=1;i<=n2;i++)
	{
	scanf("%d",&v2[i]);
	f2[v2[i]]++;
	}
for(i=1;i<=n1;i++)
	if(f2[v1[i]])
		{
		f2[v1[i]]--;
		v[++nr]=v1[i];
		}
printf("%d\n",nr);
for(i=1;i<=nr;i++)
	printf("%d ",v[i]);
return 0;
}