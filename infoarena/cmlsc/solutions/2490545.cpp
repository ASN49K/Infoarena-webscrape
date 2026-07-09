#include <cstdio>
#include <algorithm>
using namespace std;
int n,v[1027],v1[1027],dp[1027][1027],m,sol[1027];
int main () {
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;++i)
		scanf("%d", &v[i]);
	for(int i=1;i<=n;++i)
		scanf("%d", &v1[i]);
	for(int i=1;i<=m;++i)
		if(v[1]==v1[i])
			dp[1][i]=1;
		else
			dp[1][i]=max(dp[1][i-1],dp[1][i]);
	for(int i=1;i<=n;++i)
		if(v[i]==v1[1])
			dp[i][1]=1;
		else
			dp[i][1]=max(dp[i-1][1],dp[i][1]);
	for(int i=2;i<=n;++i)
		for(int j=2;j<=m;++j)
			if(v[i]==v[j])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	printf("%d\n", dp[n][m]);
	int j=m,kontor=0;
	for(int i=n;i>0 && j>0;) {
		if(v[i]==v1[j])
			sol[++kontor]=v[i],--i,--j;
		else if (dp[i][j-1]==dp[i][j])
			--j;
		else
			--i;
	}
	for(int i=kontor;i>0;--i)
		printf("%d ", sol[i]);
	return 0;
	//dp[i][j]=cmlsc folosind primele i caractere din sirul 1 si primele j caractere din sirul 2;
}
