
#include <cstdio>
#include <stack>

const int MAX_SIZE(1025);

int n, m, l;
int a [MAX_SIZE];
int b [MAX_SIZE];

int dp [MAX_SIZE] [MAX_SIZE];

inline void read (void)
{
	std::freopen("cmlsc.in","r",stdin);
	std::scanf("%d %d\n",&n,&m);
	int i;
	for (i = 1 ; i <= n ; ++i)
		std::scanf("%d",&a[i]);
	for (i = 1; i <= n ; ++i)
		std::scanf("%d",&b[i]);
	std::fclose(stdin);
}

inline void print (void)
{
	std::stack<int> stack;
	std::freopen("cmlsc.out","w",stdout);
	std::printf("%d\n",l);
	int i, j;
	i = n;
	j = m;
	while (i && j)
	{
		if (a[i] == b[j])
		{
			stack.push(a[i]);
			--i;
			--j;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
			--i;
		else
			--j;
	}
	while (!stack.empty())
	{
		std::printf("%d ",stack.top());
		stack.pop();
	}
	std::fclose(stdout);
}

inline int max (int a, int b)
{
	return a > b ? a : b;
}

inline void dynamic (void)
{
	int i, j;
	for (i = 1 ; i <= n ; ++i)
		for (j = 1 ; j <= n ; ++j)
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
	l = dp[n][m];
}

int main (void)
{
	read();
	dynamic();
	print();
	return 0;
}

