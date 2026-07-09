#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int s[5250],c[5255],b[5255];
int d[5250][5250];
int n,m,i,j,cnt;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>s[i];
    for(i=1;i<=m;i++)
        f>>c[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(s[i]==c[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
    for(i=n;i>=1;)
    {
        for(j=m;j>=1;)
        {
            if(s[i]==c[j])
            {
                b[++cnt]=s[i];
                i--;
                j--;
            }
            if(d[i][j-1]>d[i-1][j])
                j--;
            else
                i--;
        }
    }
    g<<d[n][m]<<'\n';
    for(i=cnt;i>=1;i--)
        g<<b[i]<<" ";
    return 0;
}
