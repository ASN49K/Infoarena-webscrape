#include <fstream>

using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int n,m,i,j,a[1030],b[1030],c[1030][1030],sol[1030],vf,d[1030];
void aflsir(int lin, int col)
{
    if (a[lin]==b[col])
    {
        if (d[lin]==0)
        {
            d[lin]=1;
            vf++;
            sol[vf]=a[lin];
            if (lin==1 || col==1) return;
            else aflsir(lin-1,col-1);
        }
    }
    else
    {
        if (c[lin-1][col]>c[lin][col-1]) aflsir(lin-1,col);
        else if (c[lin-1][col]<c[lin][col-1]) aflsir(lin,col-1);
        else
        {
            aflsir(lin-1,col);
            aflsir(lin,col-1);
        }
    }
}
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
    aflsir(n,m);
    for (i=vf; i>=1; i--) g<<sol[i]<<" ";
    return 0;
}
