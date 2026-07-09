#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define REP(i, a, b) \
	for (int i=int(a); i<=int(b); ++i)

#define N 1024

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int longest[N], opt[N][N];
int s1[N], s2[N];
int n1, n2;

void read() {
	f >> n1 >> n2;
	REP (i, 1, n1)
		f >> s1[i];
	REP (i, 1, n2)
		f >> s2[i];

}

int lcs() {
	REP (i, 1, n1){
		REP (j, 1, n2){
			if (s1[i] == s2[j]){
				opt[i][j] = opt[i-1][j-1]+1;
			}
			else{
				opt[i][j] = max(opt[i][j-1], opt[i-1][j]);
			}
		}
	}
	g << opt[n1][n2] << endl;
}

void trace() {

	int k = opt[n1][n2]-1;
	for (int i=n1, j=n2; i>=0 && j>= 0;) {
		if (s1[i] == s2[j]){
			longest[k--] = s1[i];
			i--;
			j--;
		}
		else if (opt[i][j-1] < opt[i-1][j])
			i--;
		else
			j--;
	}
	REP (i, 0, opt[n1][n2]-1)
		g << longest[i] << " ";
}

int main () {

	read();
	lcs();
	trace();

	f.close();
	g.close();

	return 0;
}