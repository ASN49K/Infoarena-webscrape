#include <cstdio>
#define maxn 1024

short a[maxn],b[maxn], dp[maxn][maxn],t[maxn][maxn];
int n,m;

inline void f(int i, int j)
{
    if(t[i][j]!=0)
    {
	if(t[i][j]==1){f(i-1, j-1);printf("%d ", a[i]);}
	if(t[i][j]==2) f(i-1, j);
	if(t[i][j]==3) f(i, j-1);
	
	    
    }
    
}
void solve()
{   
    int i, j;

    for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	    if(a[i]==b[j])
		dp[i][j]=dp[i-1][j-1]+1,t[i][j]=1;
	    else
		if(dp[i-1][j]>dp[i][j-1])
		    dp[i][j]=dp[i-1][j], t[i][j]=2;
		else dp[i][j]=dp[i][j-1],t[i][j]=3;

    freopen("cmlsc.out","w",stdout);
    printf("%d\n", dp[n][m]);
    f(n,m);
    
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    scanf("%d %d\n", &n, &m);
    int i;
    for(i=1;i<=n;++i) scanf("%d ", a+i);
    for(i=1;i<=m;++i) scanf("%d ", b+i);
    solve();
    return 0;
}

