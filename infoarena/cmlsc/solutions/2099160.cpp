#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int c[1025][1025],a[1025],b[1025],n,m,k,rez[1025],j;
int main()
{
    int n,m;
    f>>n>>m;
    for (int i=1;i<=n;++i) f>>a[i];
    for (int i=1;i<=m;++i) f>>b[i];
    for (int i=1;i<=n;++i)


    {
        for (int j=1;j<=m;++j)
        {
            if (a[i]==b[j]) {c[i][j]=c[i-1][j-1]+1;}
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }


    while (n>0&&m>0)
    {
        if (a[n]==b[m])
        {
            rez[k++]=a[n];
            n--; m--;
        }
        else if (c[n-1][m]>c[n][m-1]) n--;
        else m--;
    }

    g<<k<<'\n';
    for (int i=k-1;i>=0;--i) g<<rez[i]<<" ";
    return 0;
}
