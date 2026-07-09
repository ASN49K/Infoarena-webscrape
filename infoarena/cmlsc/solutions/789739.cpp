#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("cmlsc.in");
	int M, N;

	fin >> M >> N;
	int mv[M];
	for(int i = 0; i < M; i++)
		fin >> mv[i];

	int nv[N];
	for(int i = 0; i < N; i++)
		fin >> nv[i];

	fin.close();

	int dyn[N+1][M+1];
	for(int i = 0; i <= N; i++)
		dyn[i][0] = 0;

	for(int i = 0; i <= M; i++)
		dyn[0][i] = 0;

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			if(nv[i-1] == mv[j-1]) {
				dyn[i][j] = dyn[i-1][j-1] + 1;
			}
			else if(dyn[i][j-1] > dyn[i-1][j]) {
				dyn[i][j] = dyn[i][j-1];
			}
			else {
				dyn[i][j] = dyn[i-1][j];
			}
	int k = 0, vals[dyn[N][M]];
	int i = N, j = M;
	
	while( i != 0 && j != 0) {
		if((dyn[i-1][j-1] > dyn[i][j-1]) && (dyn[i-1][j-1] > dyn[i-1][j])) {
			vals[k++] = nv[i-1];
			i--;
			j--;
		}
		else if(dyn[i][j-1] > dyn[i-1][j]) {
			j--;
		}
		else {
			i--;
		}
	}

	ofstream fout("cmlsc.out");
	fout << dyn[N][M] << endl;
	for(i = k-1; i >= 0; i--)
		fout << vals[i] << " ";
	fout.close();
}
