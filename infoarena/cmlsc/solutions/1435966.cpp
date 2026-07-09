#include <fstream>
int n, m, i, j, s1[1025], s2[1025], d[1025][1025], lcs[1025], l;
int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (i=1;i<=n;i++)
		scanf("%d", &s1[i]);
	for (i=1;i<=m;i++)
		scanf("%d", &s2[i]);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (s1[i]==s2[j])
				d[i][j]=d[i-1][j-1]+1;
			else
				d[i][j]=std::max(d[i-1][j], d[i][j-1]);
	printf("%d\n", d[n][m]);
	i=j=1;
	while (i<=n && j<=m)
		if (s1[i]==s2[j])
		{
			lcs[++l]=s1[i];
			i++;
			j++;
		}
		else
			if (d[i+1][j]>d[i][j+1])
				i++;
			else
				j++;
	for (i=1;i<=l;i++)
		printf("%d ", lcs[i]);
	return 0;
}