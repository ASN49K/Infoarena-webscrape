#include <fstream>

using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int a[1<<11], b[1<<11], d[1<<11][1<<11], sol[1<<11];
int n, m, i, j, k;

int main()
{
    f>>n>>m;
    for ( i=1; i <= n; i++ )
        f>>a[i];
    for ( i=1; i <= m; i++ )
        f>>b[i];

    for ( i=1; i <= n; i++ )
        for ( j=1; j <= m; j++ )
            if ( a[i] == b[j] )
                d[i][j] = d[i-1][j-1]+1;
            else d[i][j] = max ( d[i][j-1], d[i-1][j] );
    i = n; j = m;
    while ( i && j ){
        if ( a[i] == b[j] )
            sol[++k] = a[i], i--, j--;
        else if ( d[i-1][j] > d[i][j-1] ) i--;
            else j--;
    }
    g<<k<<"\n";
    for ( i=k; i; i-- )
        g<<sol[i]<<" ";
    return 0;
}
