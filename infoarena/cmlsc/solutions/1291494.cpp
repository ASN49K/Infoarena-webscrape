#include <vector>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int maxn = 1030;

int a[maxn], b[maxn], n, m, dp[maxn][maxn];

inline void reconstruct(int x, int y) {
	if(x < 1 || y < 1)
		return ;
	if(a[x] == b[y]) {
		reconstruct(x - 1, y - 1);
		fout << a[x] << ' ';
		return ;
	}	
	if(dp[x - 1][y] > dp[x][y - 1])
		reconstruct(x - 1, y);
	else
		reconstruct(x, y - 1);
}

inline int lcs() {
	for(int i = 1 ; i <= n ; ++ i)
		for(int j = 1 ; j <= m ; ++ j)
			if(a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	return dp[n][m];
}

int main() {
	fin >> n >> m;
	for(int i = 1 ; i <= n ; ++ i)
		fin >> a[i];
	for(int i = 1 ; i <= m ; ++ i)
		fin >> b[i];
	
	fout << lcs() << '\n';
	reconstruct(n, m);
}
