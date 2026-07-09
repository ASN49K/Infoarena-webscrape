#include <iostream>
#include <fstream>

using namespace std;

int n, m, v[1040][1040], x[1040], y[1040], ans[1040], cnt=0, sgn[1040][1040];



int backtrack (int i, int j)
{
    if (i==0 or j==0)
        return 0;
    if (sgn[i][j]==11)
    {
        if (i>0 and j>0)
        backtrack(i-1, j-1);
        ans[cnt++]=x[i];
    }
    if (sgn[i][j]==10)
        if (j>0)
        backtrack(i, j-1);
    if (sgn[i][j]==1)
        if (i>0)
        backtrack(i-1, j);
}

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    f >> n >> m;
    for (int i=1; i<=n; i++)
        f >> x[i];
    for (int j=1; j<=m; j++)
        f >> y[j];

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
    {
        if (x[i]==y[j])
            {v[i][j]=v[i-1][j-1]+1;
            sgn[i][j]=11;}
        else
        {
            if (v[i-1][j]>v[i][j-1])
                {sgn[i][j]=1;
                v[i][j]=v[i-1][j];}
            else
                {sgn[i][j]=10;
                v[i][j]=v[i][j-1];}
        }
    }


    g << v[n][m] << '\n';


    backtrack(n, m);



    for (int i=0; i<cnt; i++)
        g << ans[i] << " ";



    return 0;
}
