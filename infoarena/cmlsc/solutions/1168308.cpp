#include<fstream>
using namespace std;
ifstream f("cmls.in");
ofstream g("cmls.out");
int x[1024],y[1024];
short c[1025][1025];
short b[1025][1025];
void scrie(int i,int j)
{
    if (i==0 || j==0);
    else
    {
        if (b[i][j]==1) {scrie(i-1,j-1);g<<x[i]<<' ';}
            else if (b[i][j]==-1) scrie(i-1,j);
                else scrie(i,j-1);
    }
}
int n,m,i,j;
int main()
{
    f>>n>>m;
    for (i=1;i<=n;++i) f>>x[i];
    for (j=1;j<=m;++j) f>>y[j];
    for (i=1;i<=n;++i)
        for (j=1;j<=m;++j)
        {
            if (x[i]==y[j])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }
            else if (c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]=-1;
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]=-2;
            }
        }
    g<<c[n][m]<<"\n";
    scrie(n,m);
    return 0;
}
