#include <iostream>
#include <fstream>
#define nmax 1050
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[nmax],b[nmax],i,fn[nmax],t,dp[nmax][nmax];
void lcs()
{
	int i,j;
    for(i=0;i<=n;i++)
	  for(j=0;j<=m;j++)
	  {
	 	if(i==0 || j==0)dp[i][j]=0;
	 	else if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
	 	else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	  }
	fout<<dp[n][m]<<endl;
	int indx=dp[n][m];
	i=n,j=m;
	while(i>0 && j>0)
	{
		if(a[i]==b[j])fn[indx]=a[i],i--,j--,indx--;
		else if(dp[i-1][j]>dp[i][j-1])i--;
		else j--;
	}
}
int main()
{
	fin>>n>>m;
	for(i=1;i<=n;i++)fin>>a[i];
	for(i=1;i<=m;i++)fin>>b[i];
	lcs();
	for(i=1;i<=dp[n][m];i++)fout<<fn[i]<<" ";
	return 0;
}

