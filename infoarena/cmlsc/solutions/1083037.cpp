#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n,m,a[1028],b[1028],d[1028][1028],sol[1028];
int main()
{
    int i,j;
    fstream f,g;
    f.open("cmlsc.in",ios::in);
    g.open("cmlsc.out",ios::out);
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>a[i];
    for (j=1;j<=m;j++)
        f>>b[j];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;

            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    g<<d[n][m]<<"\n";
    i=n;
    j=m;
    while (1)
    {
        if (a[i]==b[j])
        {
            sol[++sol[0]]=a[i];
            i--;
            j--;
                 if (sol[0]==d[n][m])
            break;

        }
        else
        if (d[i-1][j]>d[i][j-1])
            i--;
        else
            j--;
    }
    for (i=sol[0];i>=1;i--)
        g<<sol[i]<<" ";
}
