#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

/**

1. dp[i][j] = lungimea maxima a unui subsir comun prefixelor de
              lungime i si j din a, respectiv b

2. dp[i][j] = max(dp[i-1][j], dp[i][j-1]), daca a[i] != b[j]
   dp[i][j] = 1 + dp[i-1][j-1], daca a[i] = b[j]

*/
int a[1025], b[1025], dp[1025][1025], n, m;

void refac_subsir(int l, int c)
{
	if (l == 0 || c == 0)
    {
		return;
    }

	if (a[l] == b[c])
	{
		refac_subsir(l - 1, c - 1);
		out << a[l] << " ";
	}
	else if (dp[l - 1][c] > dp[l][c - 1])
	{
		refac_subsir(l - 1, c);
	}
	else
	{
		refac_subsir(l, c - 1);
	}
}

int main()
{
	in >> n >> m;
	for (int i = 1; i <= n; i++)
    {
		in >> a[i];
    }
	for (int i = 1; i <= m; i++)
    {
        in >> b[i];
    }

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i] != b[j])
            {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
			else
            {
				dp[i][j] = 1 + dp[i - 1][j - 1];
            }
		}
	}
	out << dp[n][m] << "\n";
	refac_subsir(n, m);

	in.close();
	out.close();
	return 0;
}
