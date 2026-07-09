#include <iostream>
#include <fstream>

using namespace std;

typedef struct {
	int len;
	int dir;
} emat;

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

	emat dyn[N+1][M+1];
	for(int i = 0; i <= N; i++)
		dyn[i][0].len = 0;

	for(int i = 0; i <= M; i++)
		dyn[0][i].len = 0;

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			if(nv[i-1] == mv[j-1]) {
				dyn[i][j].len = dyn[i-1][j-1].len + 1;
				dyn[i][j].dir = 2;
			}
			else if(dyn[i][j-1].len > dyn[i-1][j].len) {
				dyn[i][j].len = dyn[i][j-1].len;
				dyn[i][j].dir = 1;
			}
			else {
				dyn[i][j].len = dyn[i-1][j].len;
				dyn[i][j].dir = 3;
			}
	int k = 0, vals[dyn[N][M].len];
	int i = N, j = M;
	
	while( i != 0 && j != 0) {
		if(dyn[i][j].dir == 2) {
			vals[k++] = nv[i-1];
			i--;
			j--;
		}
		else if(dyn[i][j].dir == 1) {
			j--;
		}
		else {
			i--;
		}
	}

	ofstream fout("cmlsc.out");
	for(i = k-1; i >= 0; i--)
		fout << vals[i] << " ";
	fout.close();
}
