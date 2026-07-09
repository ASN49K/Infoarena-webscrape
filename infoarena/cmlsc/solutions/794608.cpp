#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAX = 1030;

int N,M;
int A[MAX],B[MAX];

enum {
	UP,
	LEFT,
	BOTH
};

void solve()
{
	int mat[MAX][MAX];
	char prev[MAX][MAX];
	for(int i=0;i<=N;++i)
		for(int j=0;j<=M;++j)
			mat[i][j] = 0;

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
		{
			if (mat[i][j-1] > mat[i-1][j])
			{
				mat[i][j] = mat[i][j-1];
				prev[i][j] = LEFT;
			}
			else
			{
				mat[i][j] = mat[i-1][j];
				prev[i][j] = UP;
			}

			if (A[i] == B[j])
				if (mat[i-1][j-1]+1 > mat[i][j])
				{
					mat[i][j] = mat[i-1][j-1] + 1;
					prev[i][j] = BOTH;
				}
		}

	
	ofstream fout;
	fout.open("cmlsc.out");

	fout << mat[N][M] << endl;
	int x = N,y = M;
	vector<int> sol;
	while (x > 0 && y > 0)
	{
		if (prev[x][y] == BOTH)
		{
			sol.push_back(A[x]);
			--x;
			--y;
		}
		else if (prev[x][y] == UP)
			--x;
		else if (prev[x][y] == LEFT)
			--y;
	}
	for(int i = sol.size()-1 ; i >= 0 ; --i)
		fout << sol[i] << " ";

	fout.close();
}

void read()
{
	ifstream fin;
	fin.open("cmlsc.in");

	fin >> N >> M;
	for(int i=1;i<=N;++i)
		fin >> A[i];
	for(int j=1;j<=M;++j)
		fin >> B[j];

	fin.close();
}

int main()
{
	read();
	solve();

	return 0;
}