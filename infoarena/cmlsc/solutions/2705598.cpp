#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> s;

void solve(vector<vector<int>> &matrix, vector<int> &a, vector<int> &b, int x, int y)
{
	if (a[x] == b[y])
	{
		matrix[x][y] = matrix[x - 1][y - 1] + 1;
		if(matrix[x][y] > s.size())
			s.push_back(a[x]);
	}
	else
	{
		matrix[x][y] = max(matrix[x - 1][y], matrix[x][y - 1]);
	}
}

int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	// Program
	int N, M;
	f >> N;
	f >> M;
	vector<int> a(N + 1);
	vector<int> b(M + 1);
	vector<vector<int>> matrix(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; i++)
	{
		f >> a[i];
	}
	for (int i = 1; i <= M; i++)
	{
		f >> b[i];
	}
	for (int n = 1; n <= N; n++)
	{
		for (int m = 1; m <= M; m++)
		{
			solve(matrix,a,b,n,m);
		}
	}
	g << matrix[N][M]<<endl;
	for (auto it = s.begin(); it != s.end(); it++)
	{
		g << *it << " ";
	}
	// Exit
	f.close();
	g.close();
	return 0;
}
