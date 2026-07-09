#include <fstream>
#include <vector>

const int N = (1<<10)+1;

int dp[N][N];
std::pair<int, int>prev[N][N];

int main() {
	std::ifstream fin("cmlsc.in");
	std::ofstream fout("cmlsc.out");
	int n, m;
	fin>>n>>m;
	std::vector<int>a(n+1), b(m+1);
	for(int i=1;i<=n;i++) fin>>a[i];
	for(int i=1;i<=m;i++) fin>>b[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) {
			if(a[i] == b[j])
				dp[i][j] = dp[i-1][j-1] + 1, prev[i][j] = {i-1, j-1};
			if(dp[i][j] < dp[i-1][j]) dp[i][j] = dp[i-1][j], prev[i][j] = {i-1, j};
			if(dp[i][j] < dp[i][j-1]) dp[i][j] = dp[i][j-1], prev[i][j] = {i, j-1};
		}
	fout<<dp[n][m]<<"\n";
	std::vector<int>ans;
	int x = n, y = m;
	while(x and y) {
		if(prev[x][y].first==x-1 and prev[x][y].second==y-1) ans.push_back(a[x]);
		int cx = prev[x][y].first, cy = prev[x][y].second;
		x = cx, y = cy;
	}
	for(int i=ans.size()-1;i>=0;i--) fout<<ans[i]<<" ";
}