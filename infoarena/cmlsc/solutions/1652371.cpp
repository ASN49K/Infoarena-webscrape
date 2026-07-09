#include <iostream>
#include <fstream>
#define max(a, b) ((a>b) ? a:b)
#define DMAX 1050
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int n,m,a[DMAX],b[DMAX],d[DMAX][DMAX],v[DMAX];
int main()
{
    f>>n>>m;
    for (int i=1;i<=n;i++)
        f>>a[i];
    for (int i=1;i<=m;i++)
        f>>b[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    int q=0;
    g<<d[n][m]<<'\n';
    for (int i=n,j=m;i;)
    {
        if (a[i]==b[j]) v[++q]=a[i],i--,j--;
        else if (d[i][j-1]>d[i-1][j]) j--;
        else i--;
    }
    for (int i=q;i>0;i--)
        g<<v[i]<<' ';
    return 0;
}
