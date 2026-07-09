#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1024],b[1024],n,m,l=0;
int DP[1025][1025],r;

int main()
{
	fin>>m>>n;
	for(int i=1; i<=m; i++)
	{
		fin>>a[i];
	}
	for(int j=1; j<=n; j++)
	{
		fin>>b[j];
	}
	for(int i=1; i<=m; i++)
	{
	    for(int j=1; j<=n; j++)
	    {
	        if(a[i]!=b[j])
	        {
	            DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
	        }
	        else 
	        {
	            DP[i][j]=1+DP[i-1][j-1];
	        }
	    }
	}
	fout<<DP[n][m];

    return 0;
}