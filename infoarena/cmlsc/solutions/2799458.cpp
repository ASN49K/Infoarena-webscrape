#include <bits/stdc++.h>

using namespace std;

ifstream fin("rucsac.in");
ofstream fout("rucsac.out");

int dp[2][10001];

int main()
{
    int n, w, index, i, curr_w, p, j, ans;
    fin >> n >> w;
    index = 0;
    for (i = 1; i <= n; ++i, index = 1 - index)
    {
        fin >> curr_w >> p;
        for (j = 0; j <= w; ++j)///iterez prin greutatile din dp[i-1]
        {
            if (dp[index][j] > dp[1 - index][j])
                dp[1 - index][j] = dp[index][j];
            if (j + curr_w <= w && dp[index][j] + p > dp[1 - index][j + curr_w])
                dp[1 - index][j + curr_w] = dp[index][j] + p;
        }
    }
    fin.close();
    ans = 0;
    for (i = 0; i <= w; ++i)
        if (dp[index][i] > ans)
            ans = dp[index][i];
    fout << ans;
    fout.close();

    return 0;
}