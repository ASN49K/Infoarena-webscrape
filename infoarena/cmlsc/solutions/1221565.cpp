#include<fstream>
using namespace std;
ifstream f("cmlsc.in",ios::in);
ofstream g("cmlsc.out", ios::out);
int max( int a, int b)
{
    if(a>b)
    return a;
    else
    return b;}
int main()
{
    int n,m,x[30],y[30],c[30][30],i,j,nr,lg,sir[30];
    f>>m;
    f>>n;
    for(i=1;i<=m;i++)
    f>>x[i];
    for(j=1;j<=n;j++)
    f>>y[j];
    for(i=0;i<=m;i++)
    for(j=0;j<=n;j++)
    c[i][j]=0;
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    if(x[i]==y[j])
    c[i][j]=c[i-1][j-1]+1;
    else
    c[i][j]=max(c[i-1][j],c[i][j-1]);
    g<<c[m][n];
     return 0;}
