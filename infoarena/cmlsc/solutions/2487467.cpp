#include <fstream>
#define f in
#define g out

using namespace std;
ifstream in ( "cmlsc.in" );
ofstream out( "cmlsc.out" );
int v[1<<11], w[1<<11], a[1<<11][1<<11], sol[1<<11];
int n, m, i, j, k;

int main() {
    f>>n>>m;
    for ( i=1; i <= n; i++ )
        f>>v[i];
    for ( i=1; i <= m; i++ )
        f>>w[i];
    for ( i=1; i <= n; i++ )
        for ( j=1; j <= m; j++ )
            if ( v[i] == w[j] )
                 a[i][j] = a[i-1][j-1]+1;
            else a[i][j] = max ( a[i-1][j], a[i][j-1] );
    i = n; j = m;
    while ( i && j ){
        if ( v[i] == w[j] )
            sol[++k] = v[i], i--, j--;
        else
            if ( a[i-1][j] > a[i][j-1] )
                 i--;
            else j--;
    }
    g<<k<<"\n";
    for ( i=k; i; i--) g<<sol[i]<<" ";
    return 0;
}

