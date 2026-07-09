#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1030], b[1030], sol[1030][1030], s[1030], i, j, n, m, x=0, y;

int main()
{
    f>>n>>m;
    for (i=1; i<=n; i++)
        f>>a[i];
    for (j=1; j<=m; j++)
        f>>b[j];
    for (i=0; i<=n+1; i++)
        sol[i][0]=sol[0][i]=0;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
    {
        if (a[i]==b[j])
            sol[i][j]=sol[i-1][j-1]+1;
        else
            sol[i][j]=max(max(sol[i][j-1], sol[i-1][j]), sol[i-1][j-1]);
    }
    i=n; j=m;
    while (sol[i][j]!=0)
    {
        if (a[i]==b[j])
        {
            x++;
            s[x]=a[i];
           // x++;
            i--;
            j--;
        }
        else if (sol[i-1][j]>sol[i][j-1])
            i--;
        else
            j--;
    }
   /* for (i=1; i<=n; i++)
        {for (j=1; j<=m; j++)
            g<<sol[i][j]<<" ";
            g<<endl;}*/
            g<<x<<endl;
            for (i=x; i>=1; i--)
                g<<s[i]<<" ";
}
