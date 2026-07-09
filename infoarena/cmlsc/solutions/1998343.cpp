#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,m,a[1030],b[1030], mat[1030][1030],sol[1030];
int main()
{
    int l=0;
    in>>n>>m;
    for(int i=1; i<=n; i++)
        in>>a[i];
    for(int i=1; i<=m; i++)
        in>>b[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            {
                if(a[i] == b[j])
                  mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i-1][j], mat[i][j-1]);
        }
    out<<mat[n][m]<<'\n';
    l=mat[n][m];
    int cn,cm;
    cn=n;
    cm=m;
    while( cn > 1 || cm > 1)
    {
        if(a[cn]==b[cm])
        {
            sol[l]=a[cn];
            l--;
            cn--;
            cm--;
        }
        else
        {
            if(mat[cn-1][cm] > mat[cn][cm-1])
                cn--;
            else
                cm--;
        }
    }
    l=mat[n][m];
    for(int i=1; i<=l; i++)
        out<<sol[i]<<" ";
    return 0;
}
