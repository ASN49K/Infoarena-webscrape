#include <iostream>
#include <fstream>
using namespace std;

#define REP(i, a, b) \
	for (int i=int(a); i<=int(b); ++i)

#define N 1024

int n1, n2;
int s1[N], s2[N], longest[N], opt[N][N], pre[N][N];

int main () {

	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");

	f >> n1 >> n2;
	REP (i, 1, n1)
		f >> s1[i];
	REP (i, 1, n2)
		f >> s2[i];
	
	REP (i, 0, 3) {
		REP(j, 0, 3) { 
			opt[i][j] = 0;
			pre[i][j] = 0;
		}
	}

	REP (i, 1, n1) {
		REP (j, 1, n2) {
			if (s1[i] == s2[j]) {
				opt[i][j] = opt[i-1][j-1]+1;
				pre[i][j] = 3;
			}
			else {
				if (opt[i][j-1] == opt[i-1][j]) {
					opt[i][j] = opt[i-1][j];
					pre[i][j] = 2;
				}
				else if (opt[i][j-1] > opt[i-1][j]) {
					opt[i][j] = opt[i][j-1];
					pre[i][j] = 1;
				}
				else {
					opt[i][j] = opt[i-1][j];
					pre[i][j] = 0;
				}
			}
		}
	}

	int len, i, j, k;	
	len = opt[n1][n2];
	
	i = n1;
	j = n2;
	k = len-1;
	while (opt[i][j] != 0) {
		if (pre[i][j] == 3) {
			longest[k--] = s1[i];
			i--;
			j--;
		}
		else if (pre[i][j] == 0) 
			i--;
		else 
			j--;
	}

	g << len << endl;
	REP (i, 0, len-1)
		g << longest[i] << " ";

	f.close();
	g.close();

	return 0;
}