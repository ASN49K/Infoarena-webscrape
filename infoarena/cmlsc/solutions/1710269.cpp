#include <fstream>

using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int n,m,a[1024],b[1024],d[1024][1024],sir[1024],bst;

int main()
{
    int i,j;
    f>>n>>m;
    for(i=1;i<=n;++i) f>>a[i];
    for(i=1;i<=m;++i) f>>b[i];
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if (a[i]==b[j]) d[i][j] = 1 + d[i-1][j-1];
            else
            {
                if(d[i-1][j]>d[i][j-1]) d[i][j]=d[i-1][j];
                else d[i][j]=d[i][j-1];
            }
    for (i=n, j = m; i; )
        if (a[i]==b[j])
            sir[++bst]=a[i], --i, --j;
        else if(d[i-1][j]<d[i][j-1])
            --j;
        else
            --i;
    g<<bst;
    for (i=bst;i>=1;--i) g<<sir[i];
    return 0;
}
