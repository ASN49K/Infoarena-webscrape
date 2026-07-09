#include <stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))

int a[1030],b[1030],s[1030][1030];
int rez[1030];
int n,m,nr;

int main()
{
	int i,j;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;++i)
		scanf("%d",&b[i]);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(a[i]==b[j])
				s[i][j]=s[i-1][j-1]+1;
			else s[i][j]=max(s[i-1][j],s[i][j-1]);
	printf("%d\n",s[n][m]);
		for(i=n,j=m;i;)
			if(a[i]==b[j])rez[++nr]=a[i],--i,--j;
		else if(s[i-1][j]>s[i][j-1]) i--;
			else j--;
		for(i=nr;i>=1;--i)
			printf("%d ",rez[i]);
		fclose(stdin);fclose(stdout);
			return 0;
}