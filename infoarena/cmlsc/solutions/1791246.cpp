#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
#define MAX_N 1050
int a[MAX_N],b[MAX_N];
int n,m,l;
int lmax[MAX_N][MAX_N],comun[MAX_N];
int maxx=-1;
void rec()
{
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==b[j])
                lmax[i][j]=lmax[i-1][j-1]+1;
            else
                lmax[i][j]=lmax[i-1][j-1];
            lmax[i][j]=max(lmax[i][j],max(lmax[i-1][j],lmax[i][j-1]));
            maxx=max(maxx,lmax[i][j]);
        }
    }
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];
    rec();
    g<<maxx<<"\n";
    maxx=0;
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)
            if(maxx<lmax[i][j])
            {
                maxx=lmax[i][j];
                g<<a[i]<<" ";
            }

    return 0;
}
