#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025][1025],x[1025],y[1025],m,n,k,h;
int main()
{
    int i,j;
    f>>n>>m;
    for(i=1;i<=n;i++)f>>x[i];
    for(i=1;i<=m;i++)f>>y[i];
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(x[i]==y[j])
    a[i][j]=a[i-1][j-1]+1;
    else
    if(a[i-1][j]>a[i][j-1])
        a[i][j]=a[i-1][j];
    else
        a[i][j]=a[i][j-1];
    k=n; h=m; i=0;
    int d[300];
    while(k&&h)
        if(x[k]==y[h])
    {
        i++;
        d[i]=x[k];
        k--; h--;
    }
    else
    if(a[k][h]==a[k-1][h])
    k--;
    else
    h--;
    g<<i<<'\n';
    for(j=i;j>=1;j--)
        g<<d[j]<<" ";
    return 0;
}
