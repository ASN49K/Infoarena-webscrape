#include <iostream>
#include <fstream>
using namespace std;
int i,a[1024],b[1024],n,nr,m,l[1024][1024],k[1024];
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
void rezolva()
{
    int i,j;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        if (a[i]==b[j])
        l[i][j]=l[i-1][j-1]+1;
    else
        if (l[i-1][j]>l[i][j-1])
        l[i][j]=l[i-1][j];
    else
        l[i][j]=l[i][j-1];
}
void afis(int i,int j)
{
    if (l[i][j])
        if (a[i]==b[j])
    {
        afis(i-1,j-1);
        k[++nr]=a[i];
    }
    else
        if (l[i-1][j]>l[i][j-1])
        afis(i-1,j);
    else
        afis(i,j-1);
}
int main()
{
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>a[i];
    for (i=1;i<=m;i++)
        f>>b[i];
        rezolva();
        afis(n,m);
        g<<nr<<'\n';
        for (i=1;i<=nr;i++)
            g<<k[i]<<" ";
}
