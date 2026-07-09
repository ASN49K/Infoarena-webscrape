#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n,a[20000],b[20000],sol[20000],d[20000][20000],i,j,k;
int main()
{
    f>>m>>n;
    for(i=1;i<=m;i++)
    f>>a[i];
    for(j=1;j<=n;j++)
    f>>b[j];
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    if(a[i]==b[j])
    d[i][j]=1+d[i-1][j-1];
    else
    if(d[i-1][j]>d[i][j-1])
    d[i][j]=d[i-1][j];
    else d[i][j]=d[i][j-1];
    i=m;j=n;
    while(i!=0)
{
    if(a[i]==b[j])
    {sol[++k]=a[i];
    i--;
    j--;
     }
    else
    if(d[i-1][j]<d[i][j-1])
    j--;
    else i--;}
    g<<k<<'\n';
    for(i=k;i>=1;i--)
    g<<sol[i]<<' ';
    f.close();
    g.close();
}
