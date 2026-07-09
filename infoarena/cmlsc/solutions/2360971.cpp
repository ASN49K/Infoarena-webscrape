#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int DN=1030;
int n,m,a[2][DN],dp[DN][DN];
void solve(int n,int m)
{
	if(n==0||m==0)
		return;
	if(a[0][n]==a[1][m]&&dp[n-1][m-1]+1==dp[n][m])
	{
		solve(n-1,m-1);
		fout<<a[0][n]<<' ';
		return;
	}
	if(dp[n-1][m]==dp[n][m])
		solve(n-1,m);
	else
		solve(n,m-1);
}
int main()
{
	fin>>n>>m;
	for(int i=0;i<2;i++)
		for(int j=1;j<=n;j++)
			fin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			if(a[0][i]==a[1][j])
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
		}
	fout<<dp[n][m]<<'\n';
	solve(n,m);
}
