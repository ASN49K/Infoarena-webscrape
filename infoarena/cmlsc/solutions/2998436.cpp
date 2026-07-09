#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, l;
int v[1025][1025], x[1025];
short a[1025], b[1025];

int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>a[i];
    for(int i=1; i<=m; i++)
        f>>b[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
    {
        if(a[i]==b[j])
            v[i][j]=v[i-1][j-1]+1;
        else
            v[i][j]=max(v[i-1][j], v[i][j-1]);
    }
    for(int i=n, j=m; i && j;)
    {
        if(a[i]==b[j])
        {
            x[++l]=a[i];
            i--;
            j--;
        }
        else if(v[i-1][j] < v[i][j-1])
            j--;
        else
            i--;
    }
    g<<l<<'\n';
    for(int i=l; i>0; i--)
        g<<x[i]<<" ";
    return 0;
}
