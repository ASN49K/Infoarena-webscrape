#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<unsigned short> getCLMSC(unsigned short** matrix, size_t n, size_t m, unsigned short* a, unsigned short *b)
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

FILE* stream;

int main()
{
	freopen_s(&stream, "cmlsc.in", "r", stdin);
	freopen_s(&stream, "cmlsc.out", "w", stdout);

	int n, m;
	unsigned short* a = nullptr;
	unsigned short* b = nullptr;
	unsigned short** matrix = nullptr;

	scanf_s("%d %d", &n, &m);

	a = (unsigned short*)malloc(sizeof(unsigned short) * (n + 1));
	b = (unsigned short*)malloc(sizeof(unsigned short) * (m + 1));

	matrix = (unsigned short**)malloc((n + 1) * sizeof(unsigned short*));

	for (size_t i = 0; i <= n; i++) {
		matrix[i] = (unsigned short*)malloc((m + 1) * sizeof(unsigned short));
	}

	for (size_t i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
	}

	for (size_t j = 1; j <= m; j++)
	{
		scanf_s("%hu", &b[j]);
	}

	buildSolution(matrix, n, m, a, b);
	std::vector<unsigned short> solution = getCLMSC(matrix, n, m, a, b);
	
	printf("%hu\n", solution.size());
	for (size_t num : solution)
	{
		printf("%hu ", (int)num);
	}

	return 0;
}