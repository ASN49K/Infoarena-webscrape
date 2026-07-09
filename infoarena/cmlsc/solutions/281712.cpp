#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1025;

int n, m;
int a[maxn], b[maxn];

int lcs[maxn][maxn];

void read()
{
    scanf("%d%d", &n, &m);
    int i;
    for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (i = 1; i <= m; ++i) scanf("%d", &b[i]);
}

void solve()
{
    int i, j;
    for (i = 1; i <= n; ++i)
	for (j = 1; j <= m; ++j)
	{
	    if (a[i] == b[j])
		lcs[i][j] = max(lcs[i][j], 1 + lcs[i - 1][j - 1]);
	    lcs[i][j] = max (lcs[i][j], max(lcs[i - 1][j], lcs[i][j - 1]));
	}
    printf("%d\n", lcs[n][m]);
}

void re(int i, int j)
{ 
    if (i == 1 || j == 1) return ;
    if (lcs[i][j] == 1 + lcs[i - 1][j - 1])
    {
	re(i - 1, j - 1);
	printf("%d ", a[i]);
    }
    else
    {
	if (lcs[i][j] == lcs[i - 1][j]) re(i - 1, j);
	else re(i, j - 1);
    }
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout); 
    
    read();
    solve();
    re(n, m);

    return 0;
}
