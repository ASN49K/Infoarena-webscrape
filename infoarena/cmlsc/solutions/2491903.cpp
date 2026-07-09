#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,sol[1034],dp[1034][1034],v[1034],v1[1034];
int main () {
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;++i)
		scanf("%d", &v[i]);
	for(int i=1;i<=m;++i)
		scanf("%d", &v1[i]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(v[i]==v1[j])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	printf("%d\n", dp[n][m]);
	int i=n,j=m;
	while(i>=1) {
		if(v[i]==v1[j])
			sol[++sol[0]]=v[i],--i,--j;
		else {
			if(dp[i-1][j]==dp[i][j])
				--i;
			else
				--j;
		}
	}
	for(int i=sol[0];i>0;--i)
		printf("%d ", sol[i]);
	return 0;
}
