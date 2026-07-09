#include <fstream>
#define MAX 1025
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int i,j,ans[MAX],a[MAX],b[MAX],D[MAX][MAX],n,m;

int main()
{
    fin>>n>>m;
    for(i=1 ; i<=n ; ++i)
        fin>>a[i];
    for(i=1 ; i<=m ; ++i)
        fin>>b[i];

    for(i=1 ; i<=n ; ++i)
        for(j=1 ; j<=m ; ++j)
        {
            if(a[i] == b[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = max(D[i-1][j],D[i][j-1]);
        }
    fout<<D[n][m]<<'\n';

    i = n;
    j = m;
    int l;
    l = D[n][m];
    i = n;
    j = m;
    while( i && j )
    {
        if( a[i] == b[j] )
        {
            ans[ l ] = a[ i ];
            --l;
            --i;
            --j;
        }
        else if( D[ i-1 ][ j ] > D[ i ][ j-1 ] )
            --i;
        else
            --j;
    }
    for(i=1 ; i<=D[n][m] ; ++i)
        fout<<ans[i]<<' ';

return 0;
}
