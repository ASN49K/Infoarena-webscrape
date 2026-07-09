#include <iostream>
#include <cstdio>
#include <stack>
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
	bool ok1=false,ok2=false;
	FOR(i,0,N)
		if(ok1||sir1[i]==sir2[0])
			ok1=true,
			dp[i][0]=1;
	FOR(j,0,M)
		if(ok2||sir1[0]==sir2[j])
			ok2=true,
			dp[0][j]=1;

	FOR(i,1,N)
		FOR(j,1,M)
			dp[i][j]=sir1[i]==sir2[j]?1+dp[i-1][j-1]:max(dp[i-1][j],dp[i][j-1]);
}

void afisare()
{
	stack<unsigned short int> stiva;
	freopen("cmlsc.out","w",stdout);
	for(int i=N-1,j=M-1;i>=0&&j>=0;)
		if(sir1[i]==sir2[j])
			stiva.push(sir1[i]),--i,--j;
		else if(!j||(i&&dp[i-1][j]==dp[i][j]))
			i--;
		else
			j--;
	printf("%d\n",stiva.size());
	while(!stiva.empty())
		printf("%d ",stiva.top()),
		stiva.pop();
	printf("\n");
}

int main()
{
	citire();
	rezolvare();
	afisare();
	return 0;
}

