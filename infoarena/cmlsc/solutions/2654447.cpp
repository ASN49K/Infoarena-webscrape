#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

int vm[MAXN], vn[MAXN];
int mat[MAXN+1][MAXN+1];

void cmlsc(int M, int N)
{
	for (int i = 0; i < M; i++)
		mat[0][i] = 0;
	for (int i = 1; i < N; i++)
		mat[i][0] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			if (vn[i] == vm[j])
				mat[i+1][j+1] = mat[i][j] + 1;
			else
				mat[i+1][j+1] = max(mat[i][j+1], mat[i+1][j]);
		}
	}
}

vector<int> traceback(int M, int N)
{
	vector<int> res;
	res.reserve(min(N, M));

	int i = N-1, j = M-1;
	while (i != -1 && j != -1)
	{
		if (vm[j] == vn[i])
		{
			res.push_back(vm[j]);
			i--; j--;
		} else {
			if (mat[i][j+1] >= mat[i+1][j])
				i--;
			else
				j--;
		}
	}

	reverse(res.begin(), res.end());
	return res;
}

int main(int argc, char const *argv[])
{
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");

	int M, N;
	fin >> M >> N;

	for (int i = 0; i < M; i++)
		fin >> vm[i];
	for (int i = 0; i < N; i++)
		fin >> vn[i];

	cmlsc(M, N);

	vector<int> trace = traceback(M, N);
	fout << trace.size() << "\n";
	for (auto t : trace)
		fout << t << ' ';

	return 0;
}