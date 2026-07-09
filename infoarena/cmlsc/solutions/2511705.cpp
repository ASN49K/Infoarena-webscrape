#include <bits/stdc++.h>
#define NMAX 1030
#define infile "cmlsc.in"
#define outfile "cmlsc.out"

using namespace std;
int n, m, dp[NMAX][NMAX], a[NMAX], b[NMAX];

void citire()
{
    int i;
    freopen(infile, "r", stdin);

    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 1; i <= m; i++)
    {
        scanf("%d", &b[i]);
    }

    fclose(stdin);
}

int solve(int i, int j)
{
    if (dp[i][j]) return dp[i][j];

    if (i == 0 || j == 0) return 0;
    else
    {
        if (a[i] == b[j])
        {
            dp[i][j] = max(solve(i - 1, j - 1) + 1, max(solve(i - 1, j),solve(i, j - 1)));
        }
        else
        {
            dp[i][j] = max(solve(i - 1, j), solve(i, j - 1));
        }
        return dp[i][j];
    }
}

void afisare(int x)
{
    freopen(outfile, "w", stdout);

    int number_to_find = 1;
    printf("%d\n", x);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (dp[i][j] == number_to_find)
            {
                printf("%d ", a[i]);
                number_to_find++;
            }
        }
    }

    fclose(stdout);
}

int main()
{
    citire();
    afisare(solve(n, m));
    return 0;
}
