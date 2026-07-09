#include <fstream>
#include <vector>
using namespace std;

#define DMAX 1025

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, vn[DMAX], vm[DMAX];
int C[DMAX][DMAX]; // lungimea
int B[DMAX][DMAX]; // directia
vector<int> common;

void write(int i, int j){
	
	if (i * j == 0) return;

	if (B[i][j] == 3){
		write(i - 1, j - 1);
		common.push_back(vn[i]);
	}
	else if (B[i][j] == 2){
		write(i - 1, j);
	}
	else{
		write(i, j - 1);
	}
}

int main(){
	int i, j, cnt = 0;
	fin >> n >> m;
	for (i = 1; i <= n; i++)	fin >> vn[i];
	for (j = 1; j <= m; j++)	fin >> vm[j];

	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			if (vn[i] == vm[j])	{
				C[i][j] = C[i - 1][j - 1] + 1;
				B[i][j] = 3;
				// sus-stanga
			}
			else if (C[i - 1][j] >= C[i][j - 1]){
				C[i][j] = C[i - 1][j];
				B[i][j] = 2;
				//sus
			}
			else {
				C[i][j] = C[i][j - 1];
				B[i][j] = 1;
				// stanga
			}
		}
	}

	
	write(n, m);

	fout << common.size() << '\n';
	for (i = 0; i < common.size(); i++){
		fout << common[i] << ' ';
	}

	return 0;
}