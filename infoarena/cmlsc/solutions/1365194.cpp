#include <algorithm>
#include <iostream>
#include <fstream>
#include <stack>


struct vec2 {
	int x, y;

	vec2(int _x = 0, int _y = 0) {
		x = _x;
		y = _y;
	}
	bool operator == (vec2 b) {
		if (this->x == b.x && this->y == b.y) {
			return true;
		}
		return false;
	}
	bool operator != (vec2 b) {
		if (this->x == b.x && this->y == b.y) {
			return false;
		}
		return true;
	}
	void operator += (vec2 b) {
		this->x += b.x;
		this->y += b.y;
	}
};


const int MAXN = 1030;
std::ifstream f("cmlsc.in");
std::ofstream g("cmlsc.out");
int a[MAXN], n;
int b[MAXN], m;
int dp[MAXN][MAXN];
vec2 parent[MAXN][MAXN];
std::stack< int > sol;


int main()
{
	f >> n >> m;
	for (int i = 1; i <= n; i++) {
		f >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		f >> b[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				parent[i][j] = vec2(-1, -1);
			}
			else {
				if (dp[i - 1][j] > dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
					parent[i][j] = vec2(-1, 0);
				}
				else {
					dp[i][j] = dp[i][j - 1];
					parent[i][j] = vec2(0, -1);
				}
			}
		}
	}
	g << dp[n][m] << std::endl;
	
	vec2 node = vec2(n, m);
	while (node.x != 0  && node.y != 0) {
		if (a[node.x] == b[node.y]) {
			sol.push(a[node.x]);
		}
		node += parent[node.x][node.y];
	}
	while (!sol.empty()) {
		g << sol.top() << ' ';
		sol.pop();
	}
	g << std::endl;


	f.close();
	g.close();
	return 0;
}