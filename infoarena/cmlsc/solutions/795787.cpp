#include <fstream> 
#include <algorithm>

using namespace std; 

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = 1025;
int M, N, A[NMAX], B[NMAX], C[NMAX];
int dp[NMAX][NMAX];

int main()
{
	fin>>M>>N;
	for(int i = 1;i <= M;++i) {
		fin>>A[i];
	}
	for(int i = 1;i <= N;++i) {
		fin>>B[i];
	}
	for(int i = 1;i <= M;++i) {
		for(int j = 1;j <= N;++j) {
			if(A[i] == B[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
			}
 		}
	}
	for(int i = M, j = N , k = dp[M][N];k > 0;) {
		if(A[i] == B[j]) {
			C[k--] = A[i];
			i--;
			j--; 
		} else 
		if(dp[i - 1][j] > dp[i][j - 1]) {
			i--;
		} else  {
			j--;
		}
	}

	fout<<dp[M][N]<<"\n";
	for(int i = 1;i <= dp[M][N];++i) {
		fout<<C[i]<<" ";
	}
	return 0;
} 
