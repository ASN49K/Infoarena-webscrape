#include <cstdio>
#include <iomanip>
using namespace std;

FILE *f = fopen ( "cmlsc.in" , "r" ) , *g = fopen ( "cmlsc.out" , "w" );

const int MAX = 1025;
int N , M , i , j , A[MAX] , B[MAX] , d[MAX][MAX] , LEN;

void read()
{
    //A[1..N] , B[1..M]
    fscanf ( f , "%d %d" , &N , &M );
    //read A
    for ( i = 1 ; i <= N ; i ++ )
        fscanf ( f , "%d" , &A[i] );
    //read B
    for ( i = 1 ; i <= M ; i ++ )
        fscanf ( f , "%d" , &B[i] );
}

void solve()
{
    //set the values on the 0-th line and 0-th column to 0
    for ( i = 0 ; i <= N ; i ++ )
        d[0][i] = 0;
    for ( i = 0 ; i <= M ; i ++ )
        d[i][0] = 0;

    //build d s.t. d[i][j] = longest common substring that can be obtained from A[1..i] and B[1..j]
    for ( i = 1 ; i <= M ; i ++ )
        for ( j = 1 ; j <= N ; j ++ )
            if ( B[i] == A[j] )
                d [ i ] [ j ] = 1 + d [ i - 1 ] [ j - 1 ];
            else
                d [ i ] [ j ] = max ( d [ i - 1 ] [ j ] , d [ i ] [ j - 1 ] );
}

void recover ( int i , int j )
{
    if ( i > 0 && j > 0 )
    {
        if ( B [ i ] == A [ j ] )   { recover ( i - 1 , j - 1 ); fprintf ( g , "%d " , B [ i ] ); }
        else if ( d [ i ] [ j ] == d [ i - 1 ] [ j ] )      recover ( i - 1 , j );
        else                                                recover ( i , j - 1 );
    }
}

void print()
{
    //find and print the length of l.c.s
    LEN = d [ M ] [ N ];
    fprintf ( g , "%d\n" , LEN );
    //recover and print the path
    recover ( M , N );
    fprintf ( g , "\n" );
}

int main()
{
    read();
    solve();
    print();
    return 0;
}
