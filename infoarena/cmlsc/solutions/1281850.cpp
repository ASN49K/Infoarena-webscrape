#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <deque>
#include <bitset>
#include <complex>
#include <functional>
#include <memory>
#include <numeric>
#define x first
#define y second
typedef std::pair<int, int> pii;

using namespace std;

int a[1025][1025];

int main () {
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	int n, m, x[1025], y[1025], mac[1025];
	fin >> n >> m;
	for(int i = 1; i <= n; i++)
		fin >> x[i];
	for(int i = 1; i <= m; i++)
		fin >> y[i];
	int cn = n, cm = m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(x[i] == y[j])
				a[i][j] = a[i - 1][j - 1] + 1;
			else
				a[i][j] = max(a[i - 1][j], a[i][j - 1]);
			fout << a[n][m] << "\n";
	for(int v = a[n][m]; v > 0; v--)
	{
		for(int i = cn; i > 0; i--)
			for(int j = cm; j > 0; j--)
				if(x[i] == y[j])
				{
					mac[v] = x[i];
					cm--;
					cn--;
					i=j=-1;
				}
	}	
	for(int i = 1; i <= a[n][m]; i++)
		fout << mac[i] << " ";

	return 0;
}