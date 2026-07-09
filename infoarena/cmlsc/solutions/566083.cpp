#include <iostream>
#include <cstdio>
#include <vector>
#define FOR(i,s,f) for(int i=s;i<f;++i)

using namespace std;
const int NMAX=1024;

int N,M;
vector<unsigned short int> sir1(NMAX),sir2(NMAX);
vector< vector<int> > dp(NMAX,vector<int>(NMAX,0));

void citire()
{
	freopen("cmlsc.in","r",stdin);
	cin>>N>>M;
	FOR(i,0,N)
		cin>>sir1[i];
	FOR(i,0,M)
		cin>>sir2[i];
}

void rezolvare()
{
	FOR(i,0,N)
		dp[i][0]=sir1[i]==sir2[0];
	FOR(j,0,M)
		dp[0][j]=sir1[0]==sir2[j];

	FOR(i,1,N)
		FOR(j,1,M)
			dp[i][j]=sir1[i]==sir2[j]?1+dp[i-1][j-1]:max(dp[i-1][j],dp[i][j-1]);
}

void afisare()
{
	freopen("cmlsc.out","w",stdout);
	printf("%d\n",dp[N-1][M-1]);
	for(int i=N-1,j=M-1;i>=0&&j>=0;)
		if(sir1[i]==sir2[j])
			printf("%d ",sir1[i]),--i,--j;
		else if(!j||i&&dp[i-1][j]==dp[i][j])
			i--;
		else
			j--;
	printf("\n");
}

int main()
{
	citire();
	rezolvare();
	afisare();
	return 0;
}

