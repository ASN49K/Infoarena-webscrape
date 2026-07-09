#include <bits/stdc++.h>
using namespace std;
const int N = 1025;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m, D[N][N], x[N], y[N], s[N];
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; i++)
        f >> x[i];
    for(int i = 1; i <= m; i++)
        f >> y[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(x[i] == y[j])
                D[i][j] = 1 + D[i - 1][j - 1];
            else
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);
        }
    }
    int i = n, j = m, contor = 0;
    while(i > 0 && j > 0)
    {
        if(x[i] == y[j])
        {
            s[++contor] = x[i];
            i--;
            j--;
        }
        if(D[i - 1][j] < D[i][j - 1])
            j--;
        else
            i--;
    }
    for(i = contor; i > 0; i--)
        g << s[i] << ' ';

    return 0;
}
