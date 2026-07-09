#include <fstream>
using namespace std;
ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");
int n,m,v1[1500],v2[1500],a[1500][1500],sir[1500];
int main()
{
    in>>n>>m;
    for (int i=1;i<=n;++i)
        in>>v1[i];
    for (int i=1;i<=m;++i)
        in>>v2[i];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        {
            if (v1[i]==v2[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    out<<a[n][m]<<'\n';
    int i,j,bst=1;
    for ( i = n, j = m; i; )
        if (v1[i] == v2[j])
            sir[++bst] = v1[i], --i, --j;
        else if (a[i-1][j] < a[i][j-1])
            --j;
        else
            --i;
    for (int k=bst;k>=2;--k)
        out<<sir[k]<<' ';
    return 0;
}

