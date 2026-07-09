
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::ifstream;
using std::ofstream;
using std::vector;
using std::max;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
	
void pd(vector<int> a, vector<int> b) {
	int m = a.size();
	int n = b.size();

	vector< vector<int> > d(m + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {

			int up = (i - 1 >= 0) ? d[i - 1][j] : 0;
			int left = (j - 1 >= 0) ? d[i][j - 1] : 0;
			int diag = (i - 1 >= 0 && j - 1 >= 0) ? d[i - 1][j - 1] : 0;

			if (a[i - 1] == b[j - 1]) {
				d[i][j] = 1 + diag;
			}
			else if(up > left){
				d[i][j] = up;
			}
			else {
				d[i][j] = left;
			}
		}
	}

	out << d[m][n] << "\n";

	int current = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] > current) {
				out << a[i - 1] << " ";
				current = d[i][j];
				i++; j++;
			}
		}
	}
}

int main(){

	int m, n;
	in >> m >> n;
	vector<int> a, b;

	while (m--) {
		int x; in >> x;
		a.push_back(x);
	}

	while (n--) {
		int x; in >> x;
		b.push_back(x);
	}

	pd(a, b);
}