#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
#define nmax 1030
int max(int a, int b)
{
    if (a>=b)
        return a;
    else return b;
}
int main()
{   int ma[400][400],a[nmax],b[nmax],i,j,n,m,x,sol[nmax];
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>a[i];
    for (i=1;i<=m;i++)
        f>>b[i];
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            {
                if (a[i]==b[j])
                    ma[i][j]=1+ma[i-1][j-1];
                else ma[i][j]=max(ma[i-1][j],ma[i][j-1]);
            }
    i=n;j=m;
    x=1;
    g<<ma[n][m]<<"\n";
    while (ma[i][j])
    {
        while (ma[i][j]==ma[i-1][j])
        i--;
        while (ma[i][j]==ma[i][j-1])
        j--;
        sol[x]=a[i];
        x++;
        i--; j--;

    }
    for (i=1;i<x;i++)
    g<<sol[i]<<" ";
    f.close();
    g.close();
    return 0;
}
