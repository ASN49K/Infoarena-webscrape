# include <iostream>
# include <fstream>
# define maxn 1024
# include <algorithm>
# include <cstdio>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[maxn], b[maxn], sol[maxn][maxn],n,m;

void back(int i, int j)
{
    if((i==0) || (j==0))
        return;
    else
    {
        if(a[i]==b[j])
        {
            g<<a[i]<<" ";
            back(i-1, j-1);
        }
        else
        {
            if(sol[i-1][j]>sol[i][j-1])
                 back(i-1,j);
            else
                 back(i,j-1);
        }
    }
}

int main()
{
    int i,j;
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(j=1; j<=m; j++)
        f>>b[j];

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                sol[i][j]=sol[i-1][j-1]+1;
            }
            else
                sol[i][j]=max(sol[i-1][j], sol[i][j-1]);

        }

        g<<sol[n][m]<<'\n';

        back(n,m);

    return 0;
}
