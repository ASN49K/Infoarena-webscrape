#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, l;
int a[1025], b[1025];
int v[1024][1024], x[1024];


int main()
{
    f>>m>>n;
    for(int i=1; i<=m; i++)
        f>>a[i];
    for(int i=1; i<=n; i++)
        f>>b[i];
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
    {
        if(a[i]==b[j])
            v[i][j]=1+v[i-1][j-1];
        else
            v[i][j]=max(v[i-1][j], v[i][j-1]);
    }
    for(int i=m, j=n; i;)
        if(a[i]==b[j])
            x[++l]=a[i], --i, --j;
        else if(v[i-1][j]<v[i][j-1])
            --j;
        else
            --i;
    g<<l<<'\n';
    for(int i=l; i>0; i--)
        g<<x[i]<<" ";
    return 0;
}
