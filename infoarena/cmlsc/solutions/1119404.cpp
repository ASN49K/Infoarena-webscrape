#include <cstdio>
#include <vector>
#include <map>

#define NMax 1026

using namespace std;

long n, m;
long v1[NMax], v2[NMax], v[NMax][NMax];
vector<long> mutualElements;
pair<long, long> tback[NMax][NMax], now;

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
            if ( v[i - 1][j] > v[i][j - 1] )
                v[i][j] = v[i - 1][j],
                tback[i][j] = make_pair ( -1, 0 );
            else
                v[i][j] = v[i][j - 1],
                tback[i][j] = make_pair ( 0, -1 );

            if ( v[i - 1][j - 1] + ( v1[i] == v2[j] ) >= v[i][j] )
                v[i][j] = v[i - 1][j - 1] + ( v1[i] == v2[j] ),
                tback [i][j] = make_pair ( -1, -1 );
    }

    printf ( "%ld\n", v[n][m] );
    now = tback[n][m];
    for ( long i = n, j = m; i > 0 && j > 0; i += now.first, j += now.second, now = tback[i][j] )
        if ( v1[i] == v2[j] )
            mutualElements.push_back( v1[i] );

    for ( vector<long>::reverse_iterator i = mutualElements.rbegin ( ); i != mutualElements.rend ( ); i++ )
        printf ( "%ld ", *i );
    printf ( "\n" );

    return 0;
}
