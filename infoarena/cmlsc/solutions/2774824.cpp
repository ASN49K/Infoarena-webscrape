#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int v[1024];
int main (){
	int m, n; fin>>m>>n;
	int a[m], b[n], dp[m][n];
	for (int i=0; i<m; ++i){
		fin>>a[i];
	}
	for (int i=0; i<n; ++i){
		fin>>b[i];
	}
	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			if (a[i]==b[j]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}
	int r=0;
	for (int i=m, j=n; i; --i){
		if (a[i]==b[j]){
			v[r]=a[i];
			++r; --j;		
		}
		else if (dp[i-1][j]<dp[i][j-1])	{
			--j;
			++i;
		}
	}
	fout<<r-1<<'\n';
	for (int i=r-1; i; --i){
		fout<<v[i]<<' ';
	}
	return 0;
}