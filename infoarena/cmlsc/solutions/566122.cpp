#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#define FOR(i,f) for(int i=1;i<=f;++i)

using namespace std;
const int NMAX=1025;

int N,M;
vector<unsigned short int> sir1(NMAX),sir2(NMAX);
vector< vector<int> > dp(NMAX,vector<int>(NMAX,0));

void citire()
{
	cin>>N>>M;
	FOR(i,N)
		cin>>sir1[i];
	FOR(i,M)
		cin>>sir2[i];
}

void rezolvare()
{
	FOR(i,N)
		FOR(j,M)
			dp[i][j]=sir1[i]==sir2[j]?1+dp[i-1][j-1]:max(dp[i-1][j],dp[i][j-1]);
}

void afisare(int i, int j,int c=0)
{
	if(i==0||j==0)
		printf("%d\n",c);
	else if(sir1[i]==sir2[j])
		afisare(i-1,j-1,c+1),
		printf("%d ",sir1[i]);
	else if(j==0||i>0&&dp[i][j]==dp[i-1][j])
		afisare(i-1,j,c);
	else
		afisare(i,j-1,c);

}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	citire();
	rezolvare();
	afisare(N,M);
	printf("\n");

	return 0;
}

