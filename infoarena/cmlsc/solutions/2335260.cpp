#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int x[1030],y[1030],a[1030][1030];

void drum(int n, int m)
{
    if (a[n][m]!=0)
    {
        if (a[n][m]==a[n-1][m]) drum(n-1,m);
        else if (a[n][m]==a[n][m-1]) drum(n,m-1);
        else
        {
            drum(n-1,m-1);
            g<<x[n]<<" ";
        }
    }
}

int main()
{
    int n,m;
    f>>n>>m;

    for (int i=1;i<=n;i++) f>>x[i];
    for (int i=1;i<=m;i++) f>>y[i];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (x[i]==y[j]) a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=max(a[i-1][j],a[i][j-1]);

    g<<a[n][m]<<endl;
    drum(n,m);

    return 0;
}
