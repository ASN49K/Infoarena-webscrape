#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int x[1025][1025],n,m,l[1025],c[1025],sol[1025];

int main()
{
    f>>n>>m;

    for (int i=1;i<=n;i++)
        f>>l[i];
    for (int i=1;i<=m;i++)
        f>>c[i];

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (l[i]==c[j]) x[i][j]=x[i-1][j-1]+1;
            else
            {
                if (x[i-1][j]>x[i][j-1]) x[i][j]=x[i-1][j];
                else x[i][j]=x[i][j-1];
            }
        }
    }

    g<<x[n][m]<<endl;
    int j=m,i=n;

    while (i>0)
    {
        if (l[i]==c[j])
        {
            sol[x[i][j]]=l[i];
            i--; j--;
        }

        else
        {
            if (x[i][j-1]>x[i-1][j]) j--;
            else i--;
        }
    }

    for (int i=1;i<=x[n][m];i++)
    {
        g<<sol[i]<<" ";
    }

    return 0;
}
