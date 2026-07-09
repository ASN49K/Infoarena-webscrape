#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define NMAX 1030

#define MAX(A, B) ((A) < (B) ? (B) : (A))

int A[NMAX], B[NMAX], N, M;
int dp[NMAX][NMAX];

void citire(){
	FILE * f = fopen("cmlsc.in", "rt");
	fscanf(f, "%d %d", &M, &N);
	for(int i = 0; i < M; ++i)
		fscanf(f, "%d", &A[i]);
	for(int j = 0; j < N; ++j)
		fscanf(f, "%d", &B[j]);
	fclose(f);
}

int solve_dp(int m, int n){
	if(m < 0 || n < 0)
		return 0;
	if(dp[m][n] != -1)
		return dp[m][n];
	int m1, m2, m3;
	m1 = m2 = m3 = 0;
	if(A[m] == B[n])
		m1 = 1 + solve_dp(m-1, n-1);
	else 
		m1 = solve_dp(m-1, n-1);
	m2 = solve_dp(m-1, n);
	m3 = solve_dp(m, n-1);
	
	dp[m][n] = MAX(m3, MAX(m1, m2));
	
	return dp[m][n];
}

void solve(){
	for(int i = 0; i < M; ++i)
		for(int j = 0; j < N; ++j)
			dp[i][j] = -1;
			
	solve_dp(M-1, N-1);
}

void scriere(){
	int i = M-1, j = N-1;
	vector<int> sol;
	while(i >= 0 && j >= 0){
		if(A[i] == B[j])
			sol.push_back(A[i]), --i, --j;
		else if(dp[i-1][j] < dp[i][j-1])	
			--j;
		else
			--i;
	}
	sort(sol.begin(), sol.end());
	FILE * f = fopen("cmlsc.out", "wt");
	fprintf(f, "%d\n", dp[M-1][N-1]);
	for(unsigned i = 0; i < sol.size(); ++i)
		fprintf(f, "%d ", sol[i]);
	fclose(f);
}

int main(){
	citire();
	solve();
	scriere();
	return 0;
}
