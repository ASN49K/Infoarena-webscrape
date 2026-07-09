#include <iostream>
#include <cstdio>

using namespace std;

const int mx = 3000 ;

int n,m ;
int A[mx],B[mx] ;
int dp[mx][mx] ;

int main()
{
    freopen( "cmlsc.in" , "r" , stdin ) ;
    freopen( "cmlsc.out" , "w" , stdout ) ;

    scanf( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i ++ )
        scanf( "%d" , &A[i] ) ;
    for ( int i = 1 ; i <= m ; i ++ )
        scanf( "%d" , &B[i] ) ;

    for ( int i = 1 ; i <= n ; i ++ )
        for ( int j = 1 ; j <= m ; j ++ )
            if ( A[i] == B[j] )
                dp[i][j] = dp[i-1][j-1] + 1 ;
            else
                dp[i][j] = max( dp[i-1][j-1] , max( dp[i-1][j] , dp[i][j-1] ) ) ;

    int i = n , j = m , p = 0 , v[mx] ;

    while ( dp[i][j] )
    {
        if ( A[i] == B[j] )
        {
            v[p++] = A[i] ;
            i -- ;
            j -- ;
        }
        else if ( dp[i-1][j] == dp[i][j] )
            i -- ;
        else
            j -- ;
    }

    printf( "%d\n" , p ) ;
    while (p)
        printf( "%d " , v[--p] ) ;

    return 0;
}
