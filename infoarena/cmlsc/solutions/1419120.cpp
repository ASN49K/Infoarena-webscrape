#include <iostream>
#include <cstdio>

using namespace std;

const int mx = 1030 ;

int n,m ;
int A[mx],B[mx] ;
int mat[mx][mx] ;

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
                mat[i][j] = mat[i-1][j-1] + 1 ;
            else
                mat[i][j] = max( mat[i-1][j-1] , max( mat[i][j-1] , mat[i-1][j] ) ) ;

    int i = n , j = m , p = 0 , v[mx] ;

    while ( mat[i][j] )
        if ( A[i] == B[j] )
        {
            v[p++] = A[i] ;
            i -- ;
            j -- ;
        }
        else if ( mat[i-1][j] == mat[i][j] )
            i -- ;
        else
            j -- ;

    printf( "%d\n" , p ) ;
    while (p)
        printf( "%d " , v[--p] ) ;

    return 0;
}
