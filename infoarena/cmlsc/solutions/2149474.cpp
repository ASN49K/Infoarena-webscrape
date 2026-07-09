#include <fstream>

using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int n,m,i,j,a[1030],b[1030],c[1030][1030],sol[1030],vf;
int main()
{
    f>>n>>m;
    for (i=1; i<=n; i++)
    {
        f>>a[i];
    }
    for (i=1; i<=m; i++)
    {
        f>>b[i];
    }
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            if (a[i]==b[j]) c[i][j]=1+c[i-1][j-1];
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }
    g<<c[n][m]<<'\n';
    i=n;
    j=m;
    while (i>=1 && j>=1)
    {
        if (a[i]==b[j])
        {
            vf++;
            sol[vf]=a[i];
            i--;
            j--;
        }
        else
        {
            if (c[i-1][j]>c[i][j-1])
            {
                i--;
            }
            else j--;
        }
    }
    for (i=vf;i>=1;i--)
        g<<sol[i]<<" ";
    return 0;
}
