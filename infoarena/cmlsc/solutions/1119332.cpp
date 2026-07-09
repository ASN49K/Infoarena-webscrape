#include <cstdio>
#include <vector>

#define NMax 1026

using namespace std;

long n, m;
long v1[NMax], v2[NMax], v[NMax][NMax];
vector<long> mutualElements;

int main()
{
    freopen ( "cmlsc.in", "rt", stdin );
    freopen ( "cmlsc.out", "wt", stdout );

    scanf ( "%ld %ld", &n, &m );
    for ( long i = 1; i <= n; i++ )
        scanf ( "%ld", &v1[i] );

    for ( long i = 1; i <= m; i++ )
        scanf ( "%ld", &v2[i] );

    for ( long i = 1; i <= n; i++ )
        for ( long j = 1; j <= m; j++ ) {
            v[i][j] = max ( v[i - 1][j], v[i][j - 1] );
            if ( v1[i] == v2[j] && v[i - 1][j - 1] + 1 > v[i][j] )
                v[i][j] = v[i - 1][j - 1] + 1,
                mutualElements.push_back ( v1[i] );
    }

    printf ( "%ld\n", mutualElements.size ( ) );
    for ( long i = 0; i < mutualElements.size ( ); i++ )
        printf ( "%ld ", mutualElements[i] );
    printf ( "\n" );

    return 0;
}
