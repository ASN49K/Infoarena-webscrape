#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void solve(vector<vector<int>>& matrix, vector<int>& a, vector<int>& b, int x, int y)
{
	if (a[x] == b[y])
	{
		matrix[x][y] = matrix[x - 1][y - 1] + 1;
	}
	else
	{
		matrix[x][y] = max(matrix[x - 1][y], matrix[x][y - 1]);
	}
}
void search(vector<vector<int>>& matrix, vector<int>& a, vector<int>& b, int x, int y, int& len, vector<int>& sol)
{
	if (len == 0) return;

	if (a[x] == b[y])
	{
		len--;
		sol[len] = a[x];
		search(matrix, a, b, x - 1, y - 1, len, sol);
	}
	else
	{
		if (matrix[x - 1][y] > matrix[x][y - 1])
		{
			search(matrix, a, b, x - 1, y, len, sol);
		}
		else
		{
			search(matrix, a, b, x, y - 1, len, sol);
		}
	}
}

int main()
{

	// Program
	int N, M;
	f >> N;
	f >> M;
	vector<int> a(N + 1);
	vector<int> b(M + 1);
	for (int i = 1; i <= N; i++)
	{
		f >> a[i];
	}
	for (int i = 1; i <= M; i++)
	{
		f >> b[i];
	}

	vector<vector<int>> matrix(N + 1, vector<int>(M + 1));
	for (int n = 1; n <= N; n++)
	{
		for (int m = 1; m <= M; m++)
		{
			solve(matrix, a, b, n, m);
		}
	}
	g << matrix[N][M] << endl;

	vector<int> sol(matrix[N][M]);
	int len = matrix[N][M];
	search(matrix, a, b, N, M,len , sol);
	for (int i = 0; i < matrix[N][M]; i++)
	{
		g << sol[i] << " ";
	}
	// Exit
	f.close();
	g.close();
	return 0;
}
