#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int x[1024],y[1024],dp[1024][1024];

int main()
{
	int n,m;
	freopen("cmlsc.in","r", stdin);
	freopen("cmlsc.out","w", stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&y[i]);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(x[i]==y[j])
				dp[i][j]=1+dp[i-1][j-1];
			if(dp[i][j]<max(dp[i-1][j],dp[i][j-1]))
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
			

	printf("%d\n",dp[n][m]);
	
	int i=n,j=m;
	while(dp[i-1][j-1]!=0)
	{
		while(dp[i-1][j-1]+1!=dp[i][j])
			i--;
		printf("%d ",x[i]);
		j--;
	}


	return 0;
}
