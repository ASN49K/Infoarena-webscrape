#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,a[1025],b[1025],d[1025][1025],poz,sir[1025];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])d[i][j]=d[i-1][j-1]+1;
        else d[i][j]=max(d[i-1][j],d[i][j-1]);
    }
    poz=0;
    for(i=n;i>=1;i--)
    {
        for(j=m;j>=1;j--)
        {
            if(a[i]==b[j])
            {
                poz++;
                sir[poz]=a[i];
                i--;j--;
            }
            else if(d[i-1][j]>d[i][j-1])i--;
            else j--;
        }
    }
    g<<d[n][m]<<'\n';
    for(i=poz;i>=1;i--)
    {
        g<<sir[i]<<" ";
    }
    return 0;
}
