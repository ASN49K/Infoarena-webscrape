#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> getCLMSC(int** matrix, int n, int m, int* a, int *b)
{
	std::vector<int> solution{};
	while (m != 0 && n != 0)
	{
		if (a[n] == b[m])
		{
			solution.push_back(a[n]);
			m--; n--;
			continue;
		}

		if (matrix[n - 1][m] > matrix[n][m - 1]) n--;
		else m--;
	}

	std::reverse(solution.begin(), solution.end());
	return solution;
}

static void buildSolution(int** matrix, int n, int m, int* a, int* b)
{
	for (int i = 0; i <= m; i++) matrix[0][i] = 0;
	for (int i = 0; i <= n; i++) matrix[i][0] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i] == b[j])
			{
				matrix[i][j] = matrix[i - 1][j - 1] + 1;
			}
			else {
				matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
			}
		}
	}
}

int main()
{
	std::ifstream fin("cmlsc.in");
	std::ofstream fout("cmlsc.out");

	size_t n, m;
	int* a = nullptr;
	int* b = nullptr;
	int** matrix = nullptr;

	fin >> n >> m;

	a = (int*)malloc(sizeof(int) * (n + 1));
	b = (int*)malloc(sizeof(int) * (m + 1));

	matrix = (int**)malloc((n + 1) * sizeof(int*));\

	for (int i = 0; i <= n; i++) {
		matrix[i] = (int*)malloc((m + 1) * sizeof(int));
	}

	for (int i = 1; i <= n; i++)
	{
		fin >> a[i];
	}

	for (int j = 1; j <= m; j++)
	{
		fin >> b[j];
	}

	buildSolution(matrix, n, m, a, b);
	std::vector<int> solution = getCLMSC(matrix, n, m, a, b);

	fout<< solution.size() << std::endl;
	for (int num : solution)
	{
		fout << num << " ";
	}

	return 0;
}