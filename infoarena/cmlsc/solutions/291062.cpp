#include <stdio.h>
#define N 1025
short int s[N],t[N],m,n;
short int v[N][N];
void read()
{
	scanf("%hd%hd",&m,&n);
	int i;
	for (i=1; i<=m; i++)
		scanf("%hd",&s[i]);
	for (i=1; i<=n; i++)
		scanf("%hd",&t[i]);
}
short int max(short int a,short int b)
{
	if (a>b)
		return a;
	return b;
}
void solve1()
{
	int i,j;
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++)
			if (s[i]==t[j])
				v[i][j]=1+v[i-1][j-1];
			else
				v[i][j]=max(v[i-1][j], v[i][j-1]);
	printf("%hd\n1 1",v[m][n]);
}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	read();
	solve1();
	return 0;
}