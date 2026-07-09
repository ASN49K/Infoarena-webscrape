#include <fstream>
#include <vector>
using namespace std;
const int N = 10300;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[N][N];
int len, n, m;
int sol[N], a[N], b[N];

void READ()
{
    fin >> m >> n;
    for (int i = 1; i <= m; i++)
        fin >> a[i];
    for (int i = 1; i <= n; i++)
        fin >> b[i];
    fin.close();
}
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
    for (int i = m; i > 0;)
        for (int j = n; j > 0 and i > 0;)
            if (a[i] == b[j])
            {
                sol[++len] = a[i];
                i--;
                j--;
            }
            else if (dp[i-1][j] < dp[i][j-1])
                --j;
            else
                --i;
}


void DISPLAY()
{
    fout << dp[m][n] << "\n";
    for (int i = dp[m][n]; i >= 1; i--)
        fout << sol[i] << " ";
}

int main()
{
    READ();
    DP();
    SC();
    DISPLAY();

    return 0;
}
