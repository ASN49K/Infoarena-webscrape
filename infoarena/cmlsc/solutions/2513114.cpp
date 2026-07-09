#include <cstdio>
#include <algorithm>

using namespace std;

const int NMAX=1030;

int a[NMAX],b[NMAX];
int dp[NMAX][NMAX];

int main(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)
		scanf("%d",&b[i]);

	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

			if(a[i]==b[j])
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);

		}
	}
	
	printf("%d\n",dp[n][m]);

	int i=n,j=m;
	int cnt=0,sol[NMAX];
	while(i && j){
		if(dp[i][j]==dp[i-1][j-1]+1 && a[i]==b[j]){
			sol[++cnt]=a[i];
			i--;
			j--;
		}else
			if(dp[i][j]==dp[i-1][j])
				i--;
			else
				j--;
	}

	for(int s=dp[n][m];s>0;s--)
		printf("%d ",sol[s]);


	return 0;
}
