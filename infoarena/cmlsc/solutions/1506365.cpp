#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

vector <int> cmlsc(vector <int> a, vector <int> b) {
	int dp[a.size()][b.size()];
	int n = a.size();
	int m = b.size();
	for(int i = 0 ; i < n ; ++ i)
		if(a[i] == b[0])
			dp[i][0] = 1;
		else
			dp[i][0] = 0;
	for(int j = 0 ; j < m ; ++ j)
		if(a[0] == b[j])
			dp[0][j] = 1;
		else
			dp[0][j] = 0;
	for(int i = 1 ; i < n ; ++ i)
		for(int j = 1 ; j < m ; ++ j)
			if(a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	int i = n - 1, j = m - 1;
	vector <int> v;
	cerr << dp[n - 1][m - 1] << '\n';
	while(i >= 0 && j >= 0) {
		if(a[i] == b[j]) {
			v.push_back(a[i]);
			-- i;
			-- j;
		}
		else if(dp[i][j - 1] <= dp[i - 1][j])
			-- i;
		else
			-- j;
	}
	reverse(v.begin(), v.end());
	return v;
}

int main() {
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");

	int n, m;
	fin >> n >> m;
	vector <int> a, b;
	for(int i = 0 ; i < n ; ++ i) {
		int x;
		fin >> x;
		a.push_back(x);
	}
	for(int i = 0 ; i < m ; ++ i) {
		int x;
		fin >> x;
		b.push_back(x);
	}
	vector <int> v = cmlsc(a, b);
	fout << v.size() << '\n';
	for(auto it : v)
		fout << it << ' ';
}
