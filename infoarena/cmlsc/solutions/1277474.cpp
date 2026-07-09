#include <iostream>
#include <cstdio>
#define n_max 1025

using namespace std;

int a[n_max] , b[n_max] , n , m , mat[n_max][n_max] ;

void citire() ;
void matrice() ;
void afisare() ;

int main()
{
    freopen( "cmlsc.in" , "r" , stdin ) ;
    freopen( "cmlsc.out" , "w" , stdout ) ;
    citire() ;
    matrice() ;
    afisare() ;
    return 0;
}

void citire()
{
    scanf( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i ++ )
        scanf( "%d" , &a[i] ) ;
    for ( int j = 1 ; j <= m ; j ++ )
        scanf( "%d" , &b[j] ) ;
}

void matrice()
{
    for ( int i = 1 ; i <= n ; i ++ )
        for ( int j = 1 ; j <= m ; j ++ )
            if ( a[i] == b[j] )
                mat[i][j] = mat[i-1][j-1] + 1 ;
            else
                mat[i][j] = max( max( mat[i-1][j] , mat[i][j-1] ) , mat[i-1][j-1] ) ;
}

void afisare()
{
    int i = n , j = m , x = mat[n][m] , fin[n_max] ;
    while ( mat[i][j] > 0 )
    {
        if ( a[i] == b[j] )
        {
            fin[x--] = a[i] ;
            i -- ;
            j -- ;
        }
        else if ( mat[i-1][j] == mat[i][j] )
            i -- ;
        else
            j -- ;
    }
    printf( "%d\n" , mat[n][m] ) ;
    for ( int i = 1 ; i <= mat[n][m] ; i ++ )
        printf( "%d " , fin[i] ) ;
}
