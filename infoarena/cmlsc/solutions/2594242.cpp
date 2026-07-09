#include <fstream>

using namespace std;
const int N = 1024;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[N][N];
int len, n, m;
int sol[N], a[N], b[N];

void DP()
{
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j - 1]);
}
void SC()
{
    for (int i = m; i >= 1;)
        for (int j = n; j >= 1;)
            if (a[i] == b[j])
            {
                sol[++len] = a[i];
                i--;
                j--;
            }

            else if (dp[i-1][j] < dp[i][j-1])
                j--;
            else i--;
}

int main()
{
    fin >> m >> n;
    for (int i = 1; i <= m; i++)
        fin >> a[i];
    for (int i = 1; i <= n; i++)
        fin >> b[i];
        fin.close();
    DP();
    SC();
    fout << len << "\n";
    for (int i = len; i >= 1; i--)
        fout << sol[i] << " ";
    fout.close();
    return 0;
}
