#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<unsigned short> getCLMSC(unsigned short** matrix, size_t n, size_t m, unsigned short* a, unsigned short* b)
{
	std::vector<unsigned short> solution{};
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

static void buildSolution(unsigned short** matrix, size_t n, size_t m, unsigned short* a, unsigned short* b)
{
	for (size_t i = 0; i <= m; i++) matrix[0][i] = 0;
	for (size_t i = 0; i <= n; i++) matrix[i][0] = 0;

	for (size_t i = 1; i <= n; i++)
	{
		for (size_t j = 1; j <= m; j++)
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
	unsigned short* a = nullptr;
	unsigned short* b = nullptr;
	unsigned short** matrix = nullptr;

	fin >> n >> m;

	a = (unsigned short*)malloc(sizeof(unsigned short) * (n + 1));
	b = (unsigned short*)malloc(sizeof(unsigned short) * (m + 1));

	for (size_t i = 1; i <= n; i++)
	{
		fin >> a[i];
	}

	for (size_t j = 1; j <= m; j++)
	{
		fin >> b[j];
	}

	unsigned short solution_length = 0;
	size_t start=1, cut=0;
	
    while (start < (n + 1) && start < (m + 1) && a[start] == b[start]) start++;
	while (start < n && start < m && a[n] == b[m]) m--; n--; cut++;

	std::cout << start << std::endl;
	std::cout << cut << std::endl;
	std::cout << n << " " << m << std::endl;

	matrix = (unsigned short**)malloc((n + 1) * sizeof(unsigned short*));
	for (size_t i = 0; i <= n; i++) {
		matrix[i] = (unsigned short*)malloc((m + 1) * sizeof(unsigned short));
	}

	buildSolution(matrix, n, m, a+start-1, b+start-1);
	std::vector<unsigned short> solution = getCLMSC(matrix, n, m, a+start-1, b+start-1);

	fout << solution.size() + start - 1 + cut << std::endl;
	for (size_t i=1; i < start; i++)
	{
		fout << (int)a[i] << " ";
	}

	for (size_t num : solution)
	{
		fout << (int)num << " ";
	}

	for (size_t i = n+1; i <= n + cut; i++)
	{
		std::cout << (int)a[i] << " ";
		fout << (int)a[i] << " ";
	}

	return 0;
}