#include <iostream>
#include <fstream>

using namespace std;

ifstream d("cmlsc.in");
ofstream o("cmlsc.out");

int a[1025],b[1025],c[1026][1026],n,m;

int max(int q,int p)
{
    return (q>p)?q:p;
}
void cmlsc()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i][j-1],c[i-1][j]);
        }
}
void sir()
{
    int nr=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(c[i][j]==nr)
            {
                o<<b[j]<<' ';
                nr++;
            }
}

int main()
{
    int i;
    d>>n>>m;
    for(i=1;i<=n;i++)
        d>>a[i];
    for(i=1;i<=m;i++)
        d>>b[i];
    cmlsc();
    o<<c[n][m]<<'\n';
    sir();
    return 0;
}
