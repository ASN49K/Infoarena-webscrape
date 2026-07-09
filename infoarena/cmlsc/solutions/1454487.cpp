#include <fstream>
#define maxn 1030


using namespace std;

int A[maxn], B[maxn], dp[maxn][maxn], sol[maxn];


int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int main()
{
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	int n, m, cnt = 0;

	in >> m >> n;
	for (int i = 1; i <= m; i++)
		in >> A[i];
	for (int j = 1; j <= n; j++)
		in >> B[j];

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (A[i] == B[j])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

	int i = m, j = n;

	while (i > 0 && j > 0)
	{
		if (A[i] == B[j])
		{
			sol[++cnt] = A[i];
			i--;
			j--;
		}

		else if (dp[i - 1][j] > dp[i][j - 1])
			i--;
		else
			j--;
	}
	out << cnt << "\n";
	for (int i = cnt; i >= 1; i--)
		out << sol[i] << " ";
}