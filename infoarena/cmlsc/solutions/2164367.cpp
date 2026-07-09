#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int v[1030][1030], x[1030], y[1030], i, j, m, n, sol[1030], k;
int main()
{
    fin >> n >> m;
    for (i=1; i<=n; i++)
        fin >> x[i];
    for (i=1; i<=m; i++)
        fin >> y[i];
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            if (x[i]==y[j]) v[i][j]=v[i-1][j-1]+1;
            else v[i][j]=max(v[i-1][j], v[i][j-1]);
        }
    }
    fout << v[n][m] << "\n";
    for (i=n; i>=1; i--)
    {
        for (j=m; j>=1; j--)
        {
            if (x[i]==y[j])
            {
                sol[++k]=x[i];
                i--;
                j--;
            }
            else
            {
                if (v[i-1][j]>v[i][j-1]) i--;
                else j--;
            }
        }
    }
    for (i=k; i>=1; i--)
        fout << sol[i] << " ";
    return 0;
}
