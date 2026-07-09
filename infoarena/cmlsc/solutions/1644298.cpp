#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int t[1050][1050];

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int longest_common(int *v, int *w, int n, int m) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (v[i] == w[j]) {
				t[i][j] = t[i - 1][j - 1] + 1;
			}
			else {
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
			}
		}
	}
	return t[n][m];
}

void print(int i, int j,int *v) {
	if (i == 0 || j == 0)
		return;
	if (t[i][j] == t[i - 1][j - 1]) {
		print(i - 1, j - 1, v);
		fout << v[i]<<" ";
	}
	else
		if (t[i][j] == t[i - 1][j]) {
			print(i - 1, j, v);
		}
		else
			print(i, j - 1, v);
}

int main() {
	int n, m, v[1050], w[1050];
	fin >> n >> m;
	for (int i = 1; i <= n; i++)
		fin >> v[i];
	for (int j = 1; j <= m; j++)
		fin >> w[j];
	fout << longest_common(v, w,n,m)<<endl;
	print(n, m,v);
	return 0;
}