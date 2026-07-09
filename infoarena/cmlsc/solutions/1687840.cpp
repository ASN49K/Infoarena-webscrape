#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int v[1030],w[1030],a[1030][1030],n,m,i,j,sir[1032],nr;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>v[i];
    for(i=1;i<=m;i++)
        f>>w[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(v[i]==w[j])
        a[i][j]=a[i-1][j-1]+1;
    else
        a[i][j]=max(a[i-1][j],a[i][j-1]);
    for(i=n,j=m;i;)
        if(v[i]==w[j])
    {
        sir[++nr]=v[i];
        i--;j--;
    }
    else
        if(a[i-1][j]>a[i][j-1])
        i--;
        else
        j--;
    for(i=nr;i;i--)
        cout<<sir[i]<<' ';
    return 0;
}
