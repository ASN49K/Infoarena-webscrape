#include <bits/stdc++.h>
using namespace std;

ofstream fout("cmlsc.out");

int n, m;
int nsol;
int a[1030];
int b[1030];
int v[1030*1030];
int dp[1030][1030];

void Afisare()
{
    int i, j;

    for(i = 1; i <= n; i++)
    {
         for(j = 1; j <= m; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }

}

void Read()
{
    ifstream fin("cmlsc.in");
    int i;

    fin >> n >> m;

    for(i = 1; i <= n; i++)
        fin >> a[i];
    for(i = 1; i<= m; i++)
        fin >> b[i];

    fin.close();
}

void Form()
{
    int i, j;

    for(i = 1; i <= n; i++)
         for(j = 1; j <= m; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    fout << dp[n][m] << "\n";
}

void Solve()
{
    Form();

    int i, j;

    i = n; j = m;

    while(i > 0 && j > 0)
    {
        if(a[i] == b[j])
        {
            v[++nsol] = a[i];
            i--; j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }

    for(i = nsol; i >= 1; i--)
        fout << v[i] << " ";
    fout << "\n";
    fout.close();
}
int main()
{
    Read();
    Solve();

    return 0;
}
