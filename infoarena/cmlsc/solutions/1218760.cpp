#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int n, m, a[2000], b[2000], c[1025][1025];

int main() {
	
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		if (a[i] == b[j]) {
			c[i][j] = 1 + c[i-1][j-1];
		} else {
			c[i][j] = max(c[i-1][j], c[i][j-1]);
		}
	}
	
	cout << c[n][m] << "\n";
	
	pair<int,int> it = make_pair(n, m);
	vector<int> sol;
	
	while (it.first != 0) {
		if (a[it.first] == b[it.second]) {
			sol.push_back(a[it.first]);
			it = make_pair(it.first-1, it.second-1);
		} else {
			if (c[it.first-1][it.second] > c[it.first][it.second-1]) {
				it = make_pair(it.first-1, it.second);
			} else {
				it = make_pair(it.first, it.second-1);
			}
		}
	}
	for (int i = sol.size() - 1; i >= 0; i--) {
		cout << sol[i] << " ";
	}
	
	return 0;
}
