#include<stdio.h>
#define NM 1025

int c[NM][NM],n,m,a[NM],b[NM],s[NM];

inline int max(int a,int b){if(a>=b)return a;return b;}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=m;i++)scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			{
			if(a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else
				c[i][j]=max(c[i-1][j],c[i][j-1]);
			}
	printf("%d\n",c[n][m]);
	i=n;j=m;
	k=0;
	while(i&&j)
		{
		if(a[i]==b[j])
			{
			s[++k]=a[i];
			i--;j--;
			}
		else
			{
			if(c[i-1][j]>=c[i][j-1]) i--;
			else j--;
			}
		}
	for(i=k;i>0;i--)printf("%d ",s[i]);
	return 0;
}