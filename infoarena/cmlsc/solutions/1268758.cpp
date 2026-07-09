#include <cstdio>
#include <algorithm>

using namespace std;

const int nmax=1024;

int a[nmax+1], b[nmax+1];
int dp[nmax+1][nmax+1];
int ans[nmax+1];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d", &b[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i]==b[j])
				dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	int lg=0;
	for(int i=n, j=m; i>0; )
	{
		if(a[i] == b[j])
		{
			ans[++lg]=a[i];
			i--; j--;
		}
		else if(dp[i-1][j] < dp[i][j-1])
			j--;
		else i--;
	}
	printf("%d\n", lg);
	for(int i=lg; i>0; i--)
		printf("%d ", ans[i]);
    return 0;
}
