#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define NMAX 1250
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, a[NMAX], b[NMAX], lcs[NMAX][NMAX];
vector<int> ans;

int main(){
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	//fin = fopen("cmlsc.in", "r");
	//fout = fopen("cmlsc.out", "w");

	//fscanf(fin,"%d %d", &n, &m);
	fin >> n >> m;
	for (int i = 1; i <= n; i++){
		//fscanf(fin, "%d", &a[i]);
		fin >> a[i];
	}
	for (int i = 1; i <= m; i++){
		//fscanf(fin,"%d", &b[i]);
		fin >> b[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (a[i] == b[j]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}

	int pozx = n, pozy = m;
	while (pozx >0 && pozy>0){
		if (a[pozx] == b[pozy]){
			ans.push_back(a[pozx]);
			pozx--; pozy--;
		}
		else{
			if (lcs[pozx-1][pozy] > lcs[pozx][pozy-1]){
				pozx--;
			}
			else pozy--;
		}
	}

	fout << lcs[n][m] << "\n";
	for (int i = ans.size() - 1; i >= 0; i--){
		//fprintf(fout, "%d ", ans[i]);
		fout << ans[i] << " ";
	}
	fout << "\n";
	//fprintf(fout, "\n");
	return 0;
}
