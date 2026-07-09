#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n,m,v[1003],v1[1003],dp[1003][1003],sol[1003];
int main () {
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;++i)
		scanf("%d", &v[i]);
	for(int i=1;i<=m;++i)
		scanf("%d", &v1[i]);
	for(int i=1;i<=m;++i)
		if(v[1]==v1[i])
			dp[1][i]=1;
		else
			dp[1][i]=max(dp[1][i],dp[1][i-1]);
	for(int i=1;i<=n;++i)
		if(v[i]==v1[1])
			dp[i][1]=1;
		else
			dp[i][1]=max(dp[i][1],dp[i-1][1]);
	for(int i=2;i<=n;++i)
		for(int j=2;j<=m;++j)
			if(v[i]==v[j])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	int i=n,j=m;
	printf("%d\n", dp[n][m]);
	while(i>1 || j>1) {
		if(v[i]==v1[j])
			sol[++sol[0]]=v[i],--i,--j;
		else if (dp[i-1][j]==dp[i][j])
			--i;
		else
			--j;
	}
	for(int i=sol[0];i>0;--i)
		printf("%d ", sol[i]);
	return 0;
}
