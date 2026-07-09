#include <stdio.h>
#include <stdlib.h>
#define MAXN 1024
short dp[MAXN + 1][MAXN + 1];
short v1[MAXN + 1];
short v2[MAXN + 1];
short lcs[MAXN + 1];
short max( short a , short b ) {
    if( a > b )
        return a;
    return b;
}
int main() {
    FILE *fin , *fout;
    int n , m , i , j , len;
    fin = fopen( "cmlsc.in" , "r" );
    fscanf( fin , "%d%d" , &n , &m );
    for( i = 1 ; i <= n ; i++ )
        fscanf( fin , "%hd" , &v1[i] );
    for( i = 1 ; i <= m ; i++ )
        fscanf( fin , "%hd" , &v2[i] );
    fclose( fin );
    for( i = 1 ; i <= n ; i++ )
        for( j = 1 ; j <= m ; j++ )
            if( v1[i] == v2[j] )
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max( dp[i - 1][j] , dp[i][j - 1] );
    len = dp[n][m];
    i = n;
    j = m;
    while( i > 0 && j > 0 ) {
        if( v1[i] == v2[j] ) {
            lcs[len - 1] = v1[i];
            i--;
            j--;
            len--;
        } else if( dp[i - 1][j] > dp[i][j - 1] )
            i--;
        else
            j--;
    }
    fout = fopen( "cmlsc.out" , "w" );
    fprintf( fout , "%hd\n" , dp[n][m] );
    for( i = 0 ; i < dp[n][m] ; i++ )
        fprintf( fout , "%hd " , lcs[i] );
    fputc( '\n' , fout );
    fclose( fout );
    return 0;
}
