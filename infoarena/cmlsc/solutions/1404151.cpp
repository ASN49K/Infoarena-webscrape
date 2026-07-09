#include <fstream>
#include <algorithm>
#include <stack>

const int MAX_SIZE(1025);

int n, m;
int v1 [MAX_SIZE], v2 [MAX_SIZE];
int Dp [MAX_SIZE] [MAX_SIZE];

inline void Read (void)
{
	std::ifstream input("cmlsc.in");
	input >> n >> m;
	for (int i(1) ; i <= n ; ++i)
		input >> v1[i];
	for (int i(1) ; i <= m ; ++i)
		input >> v2[i];
	input.close();
}

inline void Print (void)
{
	std::ofstream output("cmlsc.out");
	unsigned int size(Dp[n][m]);
	output << size << '\n';
	int i(n), j(m);
	std::stack<int> stack;
	while (stack.size() < size)
		if (v1[i] == v2[j])
		{
			stack.push(v1[i]);
			--i;
			--j;
		}
		else if (Dp[i - 1][j] == Dp[i][j])
			--i;
		else
			--j;
	while (!stack.empty())
	{
		output << stack.top() << ' ';
		stack.pop();
	}
	output.put('\n');
	output.close();
}

inline void Dynamic (void)
{
	for (int i(1) ; i <= n ; ++i)
		for (int j(1) ; j <= m ; ++j)
			if (v1[i] == v2[j])
				Dp[i][j] = Dp[i - 1][j - 1] + 1;
			else
				Dp[i][j] = std::max(Dp[i - 1][j],Dp[i][j - 1]);
}

int main (void)
{
	Read();
	Dynamic();
	Print();
	return 0;
}
