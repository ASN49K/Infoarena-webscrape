#include <fstream>
#define FOR(i,a,b) for(int i = a;i <= b;++i)

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N , M , A[1024] , B[1024] , dp[1024][1024] , sol[1024];

void lcs()
{
	FOR(i,1,N)
		FOR(j,1,M)
		dp[i][j] = (A[i] == B[j] ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j],dp[i][j - 1]));

	fout<<dp[N][M]<<'\n';
	for(int i = N , j = M;i > 0;)
	if(A[i] == B[j]) 
		sol[++sol[0]] = A[i] , i-- , j--;
	else
		if(dp[i][j - 1] > dp[i - 1][j])
			j--;
		else
			i--;
	for(int i = sol[0];i > 0;--i)
		fout<<sol[i]<<" ";
}

int main()
{
	fin>>N>>M;
	FOR(i,1,N) fin>>A[i];
	FOR(i,1,M) fin>>B[i];
	lcs();
	return 0;
}
