#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

#define max(a,b) ((a) > (b) ? (a) : (b))
int a[1024][1024], n, m;

void file_read(istream& fin, int length, vector<int>& container)
{
	for (int i = 1; i <= length; ++i) {
		int el;
		fin >> el;
		container[i] = el;
	}
}

void solve(ostream& fout, vector<int> x, vector<int> y)
{
	vector<int> s;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (x[i] == y[j])
				a[i][j] = a[i-1][j-1] + 1;
			else
				a[i][j] = max(a[i-1][j], a[i][j-1]);
		}
	}

	
	for (int i = n, j = m; (i > 0) && (j > 0);) {
		if (x[i] == y[j]) {
			s.push_back(x[i]);
			i--;
			j--;
		}
		else {
			if (a[i-1][j] > a[j-1][i])
				i--;
			else
				j--;
		}
	}
	fout << a [n][m] << endl;
	for (int i = s.size() - 1; i >= 0; --i) {
		fout << s[i] << " ";
	}

}

int main()
{
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	fin >> n >> m;
	vector<int> x(n+1), y(m+1);

	file_read(fin, n, x);
	file_read(fin, m, y);
	solve(fout, x, y);

	return 0;
}
