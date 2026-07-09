#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

#define max(a,b) ((a) > (b) ? (a) : (b))

void file_read(istream& fin, int length, vector<int>& container)
{
	for (int i = 0; i < length; ++i) {
		int el;
		fin >> el;
		container.push_back(el);
	}
}

void solve(ostream& fout, vector<int> x, vector<int> y)
{
	int a[x.size()][y.size() + 1], n, m;
	vector<int> s;
	
	n = x.size();
	m = y.size();
	a[0][0] = x[0] == y[0];
	for (int i = 1; i < n; ++i) {
		a[i][0] = max(a[i-1][0], x[i] == y[0]);
	}

	for (int  i = 1; i < m; ++i) {
		a[0][i] = max(a[0][i-1], x[0] == y[i]);
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (x[i] == y[j])
				a[i][j] = a[i-1][j-1] + 1;
			else
				a[i][j] = max(a[i-1][j], a[i][j-1]);
		}
	}

	
	for (int i = n -1, j = m - 1; (i >= 0) && (j >= 0);) {
		if (x[i] == y[j]) {
			s.push_back(x[i]);
			i--;
			j--;
		}
		else {
			if (i && j) {
				if (a[i-1][j] > a[j-1][i])
					i--;
				else
					j--;
			}
			else {
				if (i != 0)
					i--;
				if (j != 0)
					j--;
			}
		}
	}
	fout << a [n-1][m-1] << endl;
	for (int i = s.size() - 1; i >= 0; --i) {
		fout << s[i] << " ";
	}

}

int main()
{
	int m, n;
	vector<int> x, y;
	ofstream fout("cmlsc.out");
	ifstream fin("cmlsc.in");
	fin >> n >> m;
	file_read(fin, n, x);
	file_read(fin, m, y);
	solve(fout, x, y);

	return 0;
}
