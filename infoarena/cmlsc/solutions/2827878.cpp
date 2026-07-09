#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

const int NMax=1024;
int m,n;

int A[NMax], B[NMax], dp[NMax][NMax], sol[NMax];

int main()
{
	cin >> m >> n;
	for(int i = 1; i <= m; i++)
		cin >> A[i];
	for(int i = 1; i <= n; i++)
		cin >> B[i];

	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			if (A[i] == B[j])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
	int solLen = 0;
	for (int i = m, j = n; i; )
		if (A[i] == B[j])
		{
			sol[++solLen] = A[i], --i, --j;
		}
		else if (dp[i-1][j] >= dp[i][j-1])
			--i;
		else
			--j;

		cout << solLen << '\n';
		cout << sol[solLen];
	for (int i = solLen-1; i; --i)
		cout  << ' ' << sol[i];
	cout << '\n';
	return 0;
}
