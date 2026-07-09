#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

#define LL long long
#define nmax 1024
#define max(a, b) ((a < b) ? b : a)


using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void afisare() {

}

int M, N, A[nmax], B[nmax], mat[nmax][nmax], nr, sir[nmax];

int main() {
	fin >> N >> M;
	for(int i = 1; i <= N; i++)
		fin >> A[i];

	for(int i = 1; i <= M; i++)
		fin >> B[i];

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			if(A[i] == B[j])
				mat[i][j] = 1 + mat[i-1][j-1];
			else
				mat[i][j] = max(mat[i-1][j], mat[i][j-1]);

	int i = N;
	int j = M;

	while(i) {
		if(A[i] == B[j]) 
			sir[++nr] = A[i], i--, j--;
		else if(mat[i-1][j] < mat[i][j-1])
			--j;
		else
			--i;
	}

	fout << nr << "\n";
	i = nr;

	while(i) {
		fout << sir[i] << " ";
		i--;
	}
}