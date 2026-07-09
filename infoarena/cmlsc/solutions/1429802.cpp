#include <fstream>

using namespace std;
const int NMAX=1025;
int d[NMAX][NMAX], i, j, n, nr, m, sol[NMAX], a[NMAX], b[NMAX];
int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    in>>m>>n;
    for(i=1; i<=m; ++i)
        in>>a[i];
    for(j=1; j<=n; ++j)
        in>>b[j];
    for(i=1; i<=m; ++i)
        for(j=1; j<=n; ++j)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i][j-1],d[i-1][j]);
    for(i=m, j=n; i;)
        if(a[i]==b[j])

        {
            sol[++nr]=a[i];
            --i;
            --j;
        }
        else if(d[i-1][j]<d[i][j-1])
            --j;
        else
            --i;
    out<<nr<<'\n';
    for(i=nr; i>=1; --i)
        out<<sol[i]<<' ';
    out<<'\n';
    return 0;
}
