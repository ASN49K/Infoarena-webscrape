#include <bits/stdc++.h>
using namespace std;

ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
int m,n;
int X[1030],Y[1030],AUX[1030];
int DP[1030][1030];

int main()
{
	fi>>m>>n;
	for(int i=1; i<=m; i++)
		fi>>X[i];
	for(int i=1; i<=n; i++)
		fi>>Y[i];
	for(int i=1; i<=m; i++)
		for(int j=1; j<=n; j++)
		{
			DP[i][j]=max(DP[i][j-1],DP[i-1][j]);
			if(X[i]==Y[j])
				DP[i][j]=max(DP[i][j],DP[i-1][j-1]+1);
		}
	fo<<DP[m][n]<<"\n";
	for(int i=m, j=n, k=DP[m][n]; i>0 && j>0; )
	{
		if(X[i]==Y[j])
		{
			AUX[k]=X[i];
			k--;
			i--;
			j--;
		}
		else
			if(DP[i][j-1]>DP[i-1][j])
				j--;
			else
				i--;
	}
	for(int i=1; i<=DP[m][n]; i++)
		fo<<AUX[i]<<" ";
	fi.close();
	fo.close();
	return 0;
}