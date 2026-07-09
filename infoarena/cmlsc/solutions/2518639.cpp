#include <bits/stdc++.h>
#define infile "cmlsc.in"
#define outfile "cmlsc.out"
#define NMAX 1030

using namespace std;
ifstream f(infile);
ofstream g(outfile);
int a[NMAX], b[NMAX], n, m, ind, d[NMAX][NMAX], sol[NMAX];

int main()
{
    int n, m;
    f >> n >> m;
    for(int i = 1; i <= n; i++)
        f >> a[i];
    for(int i = 1; i <= m; i++)
        f >> b[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }

    int best = 0;
    for(int i = n, j = m; i && j;)
    {
        if(a[i] == b[j])
            sol[++best] = a[i], i--, j--;
        else if(d[i - 1][j] < d[i][j - 1])
            j--;
        else
            i--;
    }

    g << best << '\n';
    for(int i = best; i; i--)
        g << sol[i] << " ";
    g << '\n';
    return 0;
}
