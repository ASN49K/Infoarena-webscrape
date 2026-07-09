#include <cstdio>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int i,j,n,m,a[1025],b[1025],dp[1025][1025];
void scriere(short i,short j)
{
	if(dp[i][j]>0)
	{
		if((dp[i-1][j-1]+1)==dp[i][j] && a[i]==b[j])
		{
            scriere(i-1,j-1);
            g<<a[i]<<" ";
		}
		else
			if(dp[i-1][j]==dp[i][j])
				scriere(i-1,j);
			else scriere(i,j-1);
	}

}

int main()
{
    f>>n>>m;
	for(i=1;i<=n;i++) f>>a[i];
	for(j=1;j<=m;j++) f>>b[j];

	for(i=1;i<=n;i++)
	{	for(j=1;j<=m;j++)
		{
		    // dp[i][j] = cel mai lung subsir comun pe i , j
			if(a[i]==b[j])
				dp[i][j]=dp[i-1][j-1]+1;

 			if( max(dp[i-1][j],dp[i][j-1])>dp[i][j] )
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}

	g<<dp[n][m];
	g<<"\n";
	scriere(n,m);

	return 0;
}
