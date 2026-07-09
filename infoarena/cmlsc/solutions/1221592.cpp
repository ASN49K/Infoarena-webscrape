#include<fstream>
using namespace std;
ifstream f("cmlsc.in", ios::in);
ofstream g("cmlsc.out", ios::out);
int main()
{
    int a[30],b[30],c[30][30],i,j,m,n,l,sir[30];
    f>>m;
    f>>n;
    for(i=1;i<=m;i++)
    f>>a[i];
    for(j=1;j<=n;j++)
    f>>b[j];
    for(i=0;i<=m;i++)
    c[i][0]=0;
    for(j=0;j<=n;j++)
    c[0][j]=0;
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    if(a[i]==b[j])
    c[i][j]=c[i-1][j-1]+1;
    else
    c[i][j]=max(c[i-1][j],c[i][j-1]);
    l=1;                 
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(a[i]==b[j] && i>j)
    {
                 sir[l]=a[i];
                 l++;
                 }
    g<<c[m][n]<<'\n';
    for(i=1;i<l;i++)
    g<<sir[i]<<" ";
    return 0;}
