#include <fstream>
#include <string>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1026], b[1026];

int dp[1026][1026];


void reconstituie(int i, int j){
    if(dp[i][j] == 0)
        return;

    if(dp[i - 1][j - 1] == dp[i][j] - 1 && a[i] == b[j]){
        reconstituie(i - 1, j - 1);

        fout << a[i] << ' ';
    }
    else if(dp[i - 1][j] == dp[i][j])
        reconstituie(i - 1, j);
    else if(dp[i][j - 1] == dp[i][j])
        reconstituie(i, j - 1);
}

int main()
{
    int n, m;
    fin >> n >> m;

    for(int i = 1; i <= n;i ++)
        fin >> a[i];

    for(int i = 1; i <= m;i ++)
        fin >> b[i];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j])
                dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1] + 1));
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    fout << dp[n][m] << '\n';

    reconstituie(n, m);
    return 0;
}
