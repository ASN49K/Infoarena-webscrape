#include <bits/stdc++.h>
#define NM 1024

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

vector <int> sol, a, b;
int n, m, dp[NM][NM];

void afis (vector <int> h, int k)
{
    int i;
    for (i = 0; i < k; i ++)
        cout << h[i] << ' ';
    cout << '\n';
}

int main()
{
    fin >> n >> m;

    int i, j, x;
    for (i = 0; i < n; i ++)
    {
        fin >> x;
        a.push_back(x);
    }
    for (j = 0; j < m; j ++)
    {
        fin >> x;
        b.push_back(x);
    }

    for (i = 0; i < n; i ++)
    {
        for (j = 0; j < m; j ++)
        {
            if (a[i] == b[j])
                dp[i + 1][j + 1] = 1 + dp[i][j];
            else
                dp[i + 1][j + 1] = max (dp[i][j + 1], dp[i + 1][j]);
        }
    }

    for (i = 0; i < n; i ++)
    {
        for (j = 0; j < m; j ++)
            cout << dp[i + 1][j + 1] << ' ';
        cout << '\n';
    }

    i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0)
    {
        if (a[i] == b[j])
            sol.push_back(a[i]), i --, j --;
        else if (dp[i][j + 1] < dp[i + 1][j])
            j --;
        else
            i --;
    }

    fout << sol.size() << '\n';
    for (i = sol.size() - 1; i > -1; i --)
        fout << sol[i] << ' ';

    return 0;
}
