#include <bits/stdc++.h>

#define f first
#define s second
#define M 1234567

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1030][1030], n, m, a[1030], b[1030];

void ct()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int i = 1; i <= m; i++)
        fin >> b[i];
}

void afis()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }
}

void dinamica()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    fout << dp[n][m] << '\n';
}

void backt()
{
    vector<int> res;
    int i = n, j = m;
    while(i && j)
    {
        if(a[i] == b[j])
        {
            res.push_back(a[i]);
            i--;
            j--;
        }
        else if(dp[i - 1][j] < dp[i][j - 1])
            j--;
        else
            i--;
    }
    for(i = res.size() - 1; i >= 0; i--)
        fout << res[i] << ' ';
}

int main()
{
    ct();
    dinamica();
    //afis();
    backt();

    return 0;
}
