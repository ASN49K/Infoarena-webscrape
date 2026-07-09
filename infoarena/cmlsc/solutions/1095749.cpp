#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

#define FILE "cmlsc"

#ifdef FILE
	ifstream f(string (string(FILE) + ".in").c_str());
	ofstream g(string (string(FILE) + ".out").c_str());
#endif
#ifndef FILE
	#define f cin
	#define g cout
#endif

int i, j, n, m, x;
int v[1050][1050];
int w[1050];
vector <int> sol;


int main() {

	f >> n >> m;
	for (i=1; i<=n; i++) {
		f >> w[i];
	}

	for (i=1; i<=m; i++) {
		f >> x;
		for (j=1; j<=n; j++) {
			if (w[j] == x) {
				v[i][j] = v[i-1][j-1] + 1;
			} else {
				v[i][j] = max(v[i-1][j], v[i][j-1]);
			}
		}
	}

	i = m;
	j = n;

	while (i && j) {
		while (v[i][j] == v[i-1][j] && i) i--;
		while (v[i][j] == v[i][j-1] && j) j--;
		sol.push_back(w[j]);
		i--;
		j--;
	}

	g << sol.size() << "\n";

	for (vector<int>::reverse_iterator it = sol.rbegin(); it != sol.rend(); it++ ){
		g << *it << " ";
	}

	g << "\n";

}
