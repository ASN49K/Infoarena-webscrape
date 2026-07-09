#include <bits/stdc++.h>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int dp[1030][1030],a[1030],b[1030],v[1030];
int main()
{
	int n,m,k=0;
	in>>n>>m;
	for(int i=1;i<=n;i++)
		in>>a[i];
	for(int j=1;j<=m;j++)
		in>>b[j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int x=0;
			if(a[i]==b[j]) {
				x++;
				v[++k]=a[i];
			}
			dp[i][j]=max(dp[i-1][j-1]+x,max(dp[i][j-1],dp[i-1][j]));
		}

	out<<dp[n][m]<<"\n";
	for(int i=1;i<=k;i++)
		out<<v[i]<<" ";
	return 0;
}
