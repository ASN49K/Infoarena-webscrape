#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1030], b[1030], dp[1030][1030];
stack <int> drum;
void lcs()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
}

void generare_drum(int i, int j)
{
    if(i == 0 || j == 0)
        return;
    if(a[i] == b[j])
    {
        drum.push(a[i]);
        generare_drum(i - 1, j - 1);
    }
    else if(dp[i - 1][j] >= dp[i][j - 1])
        generare_drum(i - 1, j);
    else
        generare_drum(i, j - 1);
}

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int j = 1; j <= m; j++)
        fin >> b[j];
    lcs();
    fout << dp[n][m] << '\n';
    generare_drum(n, m);
    while(!drum.empty())
    {
        fout << drum.top() << ' ';
        drum.pop();
    }
    return 0;
}
