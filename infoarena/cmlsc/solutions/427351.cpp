# include <stdio.h>
# define max(a,b) (a) > (b) ? (a) : (b)

int n,m,s[1025][1025],i,j,a[1025],b[1025];

void drum(int x, int y)
{
	if (!s[x][y]) return;
	if (a[x]==b[y]) drum(x-1,y-1), printf("%d ", a[x]);
		else if (s[x-1][y]>s[x][y-1])
				drum(x-1,y);
			  else drum(x,y-1);
}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d", &n, &m);
	for (i=1;i<=n;i++)
		scanf("%d", &a[i]);
	for (i=1;i<=m;i++)
		scanf("%d", &b[i]);
	for (i=1;i<=n;i++)
	for (j=1;j<=m;j++)
		if (a[i]==b[j]) s[i][j]=s[i-1][j-1]+1;
			else
				s[i][j]=max(s[i-1][j],s[i][j-1]);
	printf("%d\n", s[n][m]);
	drum(n,m);
	return 0;
}
