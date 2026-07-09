#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1024],b[1024],n,m,l=1;
int DP[1025][1025];

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
	fout<<DP[m][n]<<endl;
	int k=DP[m][n],x=1,y=1,xf,yf;
	while (l<=k)
	{
		for (int i=x; i<=m; i++)
		{
			for (int j=y; j<=n; j++)
			{
				if (DP[i][j]==l and a[i]==b[j])
				{
					xf=i;
					yf=j;
				}
			}
		}
		x=xf+1;
		y=yf+1;
		fout<<a[xf]<<" ";
		l++;
	}

    return 0;
}