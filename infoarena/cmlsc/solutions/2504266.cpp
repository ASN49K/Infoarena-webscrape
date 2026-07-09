#include <fstream>
#define MAX 1030

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int n, m, a[MAX], b[MAX], dp[MAX][MAX], lcs[MAX], k;

int maxim (int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

void cmlsc (int i, int j) {
    if (i < 1 || j < 1)
        return;

    if (dp[i][j] == dp[i-1][j])
        cmlsc(i-1, j);
    else if (dp[i][j] == dp[i][j-1])
        cmlsc(i, j-1);
    else {
        lcs[++k] = a[i];
        cmlsc(i-1, j-1);
    }
}

int main()
{
    int i, j;
    fin >> n >> m;

    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (j = 1; j <= m; j++)
        fin >> b[j];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = maxim( dp[i-1][j], dp[i][j-1] );

    cmlsc(n, m);

    fout << dp[n][m] << "\n";
    for (i = k; i > 0; i--)
        fout << lcs[i] << " ";
    return 0;
}
