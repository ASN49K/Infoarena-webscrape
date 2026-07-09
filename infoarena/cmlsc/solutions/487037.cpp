# include <cstdio>

const char FIN[] = "cmlsc.in", FOU[] = "cmlsc.out" ;
const int MAX = 1 << 10 ;

char dp[MAX][MAX] ;
unsigned char A[MAX], B[MAX], sc[MAX] ;
int N, M ;

inline int max ( int a, int b ) {
    return ( a > b ? a : b ) ;
}

int main ( void ) {
    freopen ( FIN, "r", stdin ) ;
    freopen ( FOU, "w", stdout ) ;

    scanf ( "%d %d", &N, &M ) ;
    for ( int i = 1, x; i <= N; ++i ) {
        scanf ( "%d", &x ) , A[i] = x ;
    }
    for ( int i = 1, x; i <= M; ++i ) {
        scanf ( "%d", &x ) , B[i] = x ;
    }

    for ( int i = 1; i <= N; ++i ) {
        for ( int j = 1; j <= M; ++j ) {
            A[i] == B[j] ? dp[i][j] = dp[i - 1][j - 1] + 1 : dp[i][j] = max ( dp[i - 1][j], dp[i][j - 1] ) ;
        }
    }

    for ( int i = N, j = M ; i ; A[i] == B[j] ? --i, --j : ( dp[i - 1][j] < dp[i][j - 1] ) ? --j : --i ) {
        if ( A[i] == B[j] ) {
            sc[ ++sc[0] ] = A[i] ;
        }
    }

    printf ( "%d\n", sc[0] ) ;
    for ( int i = sc[0]; i ; --i ) {
        printf ( "%d ", sc[i] ) ;
    }
}

