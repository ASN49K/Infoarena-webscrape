#include <bits/stdc++.h>

using namespace std;

/**

    dp[i][j] = lungimea maxima a unui subsir obtinut din a[1...i] si b[1...j]

    solutia = dp[n][m]

    a = 3 5 7 2
    b = 6 3 1 4 4 7 2

    Recurenta

    lcs(i, j] = 1 + dp[i - 1][j - 1], daca a[i] == b[j]
    lcs[i, j] = max(lcs[i - 1][j], lcs[i][j - 1]), daca a[i] != b[j]


    DP:
       6 3 1 5 4 7 2
     3 0 1 1 1 1 1 1
     5 0 1 1 2 2 2 2
     7 0 1 1 2 2 3 3
     2 0 1 1 2 2 3 4
*/

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
