#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>

std::vector<int> lcs(const std::vector<int> &a, const std::vector<int> &b)
{
	std::vector<std::vector<int>> dp(a.size() + 1, std::vector<int>(b.size() + 1, 0));

	// compute the length of the longest subsequence
	for (size_t i = 1; i <= a.size(); ++i)
		for (size_t j = 1; j <= b.size(); ++j)
		{
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
		}

	std::vector<int> solution;
	int i = a.size(), j = b.size();

	// reconstruct a longest subsequence
	while (i && j)
	{
		if (a[i - 1] == b[j - 1])
		{
			solution.push_back(a[i - 1]);
			--i, --j;
		}
		else if (dp[i - 1][j] >= dp[i][j - 1])
		{
			--i;
		}
		else
		{
			--j;
		}
	}

	return std::vector<int>(solution.rbegin(), solution.rend());
}

int main()
{
	std::ifstream fin("cmlsc.in");
	std::ofstream fout("cmlsc.out");

	int n, m;
	fin >> n >> m;

	std::vector<int> a, b;
	std::copy_n(std::istream_iterator<int>(fin), n, std::back_inserter(a));
	std::copy_n(std::istream_iterator<int>(fin), m, std::back_inserter(b));

	auto sol = lcs(a, b);

	fout << sol.size() << std::endl;
	std::copy_n(sol.begin(), sol.size(), std::ostream_iterator<int>(fout, " "));
	fout << std::endl;

	return 0;
}
