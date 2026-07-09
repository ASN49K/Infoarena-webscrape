#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, a[1030], m, b[1030], pd[1030][1030], aux[1030];
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; i++)
        f >> a[i];
    for(int i = 1; i <= m; i++)
        f >> b[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                pd[i][j] = 1 + pd[i - 1][j - 1];
            else
                pd[i][j] = max(pd[i - 1][j] , pd[i][j - 1]);
        }
    g << pd[n][m] << '\n';
    int i = n, j = m;
    int x = pd[n][m];
    while(x)
    {
        if(a[i] == b[j])
        {
            aux[x] = a[i];
            x--;
            i--;
            j--;
        }
        else
            if(pd[i-1][j] < pd[i][j - 1])
                j--;
        else
                i--;
    }

    for(int i = 1; i <= pd[n][m]; i++)
        g << aux[i] << " ";
    return 0;
}
