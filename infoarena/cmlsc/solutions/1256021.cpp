#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define f first
#define s second
int main()
{
#ifndef ONLINE_JUDGE
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;

	vector<int> x(n), y(m);

	for(int i = 0; i < n; i++)
		cin >> x[i];

	for(int i = 0; i < m; i++)
		cin >> y[i];

	int MAX = 1025;


	vector<int> d[MAX];

	vector<pair<int, int> > LCS[MAX];

	for(int i = 0; i < n; i++) {
		d[i].resize(m, 0);
		LCS[i].resize(m, make_pair(-1, -1));
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			int p11 = 0, p10 = 0, p01 = 0;
			if(i - 1 >= 0 && j - 1 >= 0)
				p11 = d[i - 1][j - 1];

			if( i - 1 >= 0)
				p10 = d[i - 1][j];

			if( j - 1 >= 0)
				p01 = d[i][j-1];

			if(x[i] == y[j]) {
				LCS[i][j] = make_pair(i - 1, j - 1);
				d[i][j] = 1 + p11;
			}
			else if(x[i] != y[j]) {
				if(p10 > p01)
					LCS[i][j] = make_pair(i - 1, j);
				else
					LCS[i][j] = make_pair(i, j - 1); 

				d[i][j] = max(p10, p01);
			}
		}

	vector<int> sol;

	int i = n - 1, j = m - 1;
	
	while(i != -1 && j != -1) {
		if(LCS[i][j].f == i - 1 && LCS[i][j].s == j - 1) {
			sol.push_back(x[i]);
		}
		int ii = i, jj = j;
		i = LCS[ii][jj].f;
		j = LCS[ii][jj].s;
	}


	reverse(sol.begin(), sol.end());

	cout << d[n-1][m-1] << endl;

	for(int i = 0; i < sol.size(); i++)
		cout << sol[i] << " ";

	return 0;
}