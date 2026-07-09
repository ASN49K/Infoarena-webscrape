#include <fstream>
#include <algorithm>

#define MAX 1030

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int a[MAX], b[MAX];
int sir[MAX];
int sol[MAX];
int len;

bool subsir(int nivel) {
	bool ok;

	if (nivel > m)
		return false;

	for (int i = 1;i <= nivel;i ++) {
		ok = false;
		for(int j = 1;j <= m;j ++)
			if (sir[i] == b[j]) {
				ok = true;
				break;
			}
		if (!ok)
			return false;
	}
	return true;
}
void backtracking(int k, int nivel) {
	int i = 1;
	if (k == n + 1) {
		if (subsir(nivel)) {
			if (nivel > len) {
				len = nivel;
				for (i = 1;i <= nivel;i ++)
					sol[i] = sir[i];
			}	
		}
		return;
	} 

	backtracking(k + 1, nivel);
	sir[nivel + 1] = a[k];
	backtracking(k + 1, nivel + 1);
}
int main() {
	fin >> n >> m;
	for (int i = 1;i <= n;i ++)
		fin >> a[i];
	for (int i = 1;i <= m;i ++)
		fin >> b[i];

	backtracking(1, 0);

	fout << len << '\n';
	for (int i = 1;i <= len;i ++)
		fout << sol[i] << ' ';
	return 0;
}