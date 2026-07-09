#include <fstream>
#include <iostream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],lg[1025][1025];

void afis(int m, int n)
{
    if(lg[m][n])
    {
        if(a[m]==b[n])
        {
            afis(m-1,n-1);
            g<<a[m]<<' ';
        }
        else
            if(lg[m-1][n]>lg[m][n-1])
                afis(m-1,n);
            else
                afis(m,n-1);
    }
}
int main()
{
    int m,n;
    f>>m>>n;
    for(int i=1;i<=m;++i) f>>a[i];
    for(int i=1;i<=n;++i) f>>b[i];
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            if(a[i]==b[j])
                lg[i][j]=lg[i-1][j-1]+1;
            else
                lg[i][j]=max(lg[i-1][j],lg[i][j-1]);
    g<<lg[m][n]<<'\n';
    afis(m,n);
    return 0;
}
