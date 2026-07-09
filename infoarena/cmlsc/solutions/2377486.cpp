#include <bits/stdc++.h>
using namespace std;

#define nmax 1030
#define mmax 1030

int n,m,i,j;
int a[nmax], b[mmax], sol[nmax][mmax];

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void drum(int i, int j)
{
    if(i>0 && j>0)
    {
        if (a[i] == b[j])
        {
            drum(i-1, j-1);
            g<<a[i]<<" ";
        }
        else
        {
            if (sol[i-1][j] > sol[i][j-1])
                drum(i-1, j);
            else
                drum(i, j-1);
        }
    }
}

int main()
{
    f>>n>>m;

    for (i=1;i<=n;i++)
        f>>a[i];
    for (i=1;i<=m;i++)
        f>>b[i];

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if(a[i] == b[j])
                sol[i][j] = sol[i-1][j-1] + 1;
            else
                sol[i][j] = max(sol[i-1][j], sol[i][j-1]);
        }
    }

    g<<sol[n][m]<<"\n";

    drum(n,m);

    f.close();
    g.close();
    return 0;
}
