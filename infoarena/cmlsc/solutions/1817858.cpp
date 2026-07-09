#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <bitset>
#include <complex>
#include <functional>
#include <string>
#include <limits>
#include <cmath>
#include <cassert>
#include <cstdio>
#include <cstdlib>
using namespace std;
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3f;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (y > x) x = y; }
template<typename T> void _dbg(const char *sdbg, T h) { cerr << sdbg << " = " << h << "\n"; }
template<typename T, typename... U> void _dbg(const char *sdbg, T a, U... b) {
	while (*sdbg != ',') cerr << *sdbg++; cerr << " = " << a << ", "; _dbg(sdbg + 1, b...);
}
template<typename T> ostream& operator<<(ostream &os, vector<T> V) {
	os << "["; for (int i = 0; i < (int) (V.size() - 1); i++) os << V[i] << ", ";
	os << V[V.size() - 1];
	os << "]";
	return os;
}
template<typename T, typename U> ostream& operator<<(ostream &os, pair<T, U> p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int NMAX = 1234;

int a[NMAX], b[NMAX], dp[NMAX][NMAX], lcs[NMAX];
int n, m, k;

void printLCS(int i, int j) {
	if (i == 0 || j == 0) return;
	if (dp[i][j] == 1 + dp[i - 1][j - 1]) {
		printLCS(i - 1, j - 1);
		lcs[k++] = a[i];
	} else if (dp[i][j] == dp[i - 1][j]) printLCS(i - 1, j);
	else printLCS(i, j - 1);
}

int main() { ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	for (int i = 0; i <= n; i++) dp[0][i] = 0;
	for (int i = 0; i <= m; i++) dp[i][0] = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	k = 0;
	printLCS(n, m);
	cout << dp[n][m] << endl;
	for (int i = 0; i < k; i++) cout << lcs[i] << " ";
	cout << endl;
}
