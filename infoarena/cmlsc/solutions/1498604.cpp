#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int v[1050][1050];
int main()
{
    int a[1050], b[1050], m, n, j, i, c[1000], k;
    f >> n;
    f >> m;
    for (i = 1;i <= n; i++)
        f >> a[i];
    for (j = 1;j <= m; j++)
        f >> b[j];
    for (i = 1;i <= n; i++)
    {
        for (j = 1;j <= m; j++)
        {
            if (a[i] == b[j])
                v[i][j] = v[i-1][j-1] + 1;
            else
                v[i][j]=max(v [i-1][j],v[i][j-1]);
        }
    }
    g<<v[n][m]<<'\n';
    for (i = n, j = m, k = 0; i>=1 && j>=1;)
    {
        if (a[i]==b[j])
        {
            k++;
            c[k]=a[i];
            i--;
            j--;
        }
        else
        {
            if (v[i-1][j]> v[i][j-1])
                i--;
            else
                j--;
        }
        if (v[i-1][j] == 0 && v[i][j-1]==0)
        {
            k++;
            c[k]=a[i];
            break;
        }
    }
    n = k--;
    for (i = n; 1 <= i; i--)
        g << c[i] << ' ';
    return 0;
}
