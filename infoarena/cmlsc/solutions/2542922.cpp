#include <fstream>
#include <iostream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],lg[1025][1025],mi;

void afis(int m, int n, int lu)
{
    int l=0,c=0;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            if(lg[i][j]==lu && a[i]==b[j])
            {
                if(mi<a[i])
                {
                    mi=a[i];
                    l=i;
                    c=j;
                }
            }
    if(lg[l][c])
    {
        mi=0;
        g<<a[l]<<' ';
        afis(l-1,c-1,lu-1);
    }
}
int main()
{
    int m,n;
    f>>m>>n;
    for(int i=1;i<=m;++i) f>>a[i];
    for(int i=1;i<=m/2;++i) swap(a[i],a[m-i+1]);
    for(int i=1;i<=n;++i) f>>b[i];
    for(int i=1;i<=n/2;++i) swap(b[i],b[n-i+1]);
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            if(a[i]==b[j])
                lg[i][j]=lg[i-1][j-1]+1;
            else
                lg[i][j]=max(lg[i-1][j],lg[i][j-1]);
    g<<lg[m][n]<<'\n';
    afis(m,n,lg[m][n]);
    return 0;
}
