///Cmlsc InfoArena

#include <bits/stdc++.h>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1025], b[1025], d[1025][1025];

void show(int i, int j)
{
    if(i == 0 && j == 0)
        return;
    else if(a[i] == b[j])
    {
        show(i - 1, j - 1);
        g << a[i] << " ";
        return;
    }
    else if(d[i][j - 1] > d[i - 1][j])
    {
        show(i, j - 1);
        return;
    }
    show(i - 1, j);
}

int n, m, i, j;
int main()
{
    f >> n >> m;
    for(i = 1; i <= n; i++)
        f >> a[i];
    for(i = 1; i <= m; i++)
        f >> b[i];
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }
    g << d[n][m] << endl;
    show(n, m);

    return 0;
}
