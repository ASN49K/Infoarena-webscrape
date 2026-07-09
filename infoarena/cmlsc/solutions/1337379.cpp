#include <cstdio>
#include <algorithm>
#define MAX 1005

using namespace std;

int mat[MAX][MAX],dp[MAX][MAX];
int cnt [ MAX ] ;

int main()
{
    freopen("custi.in","r",stdin);
    freopen("custi.out","w",stdout);
    int n;
    scanf("%d",&n);
    for ( register int i = 1 ; i <= n ; ++ i )
        for ( register int j = 1 ; j <= n ; ++ j )
            scanf ( "%d", &mat [ i ] [ j ] ) ;
    for ( register int i = n ; i >= 1 ; -- i ){
        dp [ i ] [ n ] = mat [ i ] [ n ] ;
        dp [ n ] [ i ] = mat [ n ] [ i ] ;
    }
    for ( register int i = n - 1 ; i >= 1 ; -- i)
        for ( register int j = n - 1 ; j >= 1 ; -- j)
            if ( !mat [ i ] [ j ] )
                dp [ i ] [ j ] = 0 ;
            else {
                dp [ i ] [ j ] = 1 + min ( dp [ i + 1 ] [ j + 1 ] , min ( dp [ i ] [ j + 1 ], dp [ i + 1 ] [ j ] ) );
                cnt [ dp [ i ] [ j ] ] ++ ;
            }
    for ( register int i = n ; i >= 1 ; -- i ){
        if ( dp [ i ] [ n ] )
            cnt [ 1 ] ++ ;
        if ( dp [ n ] [ i ] )
            cnt [ 1 ] ++ ;
    }
    for ( register int i = n - 1 ; i >= 1 ; -- i )
        cnt [ i - 1 ] += cnt [ i ] ;
    for ( register int i = 1 ; i <= n ; ++ i )
        printf ( "%d\n" , cnt [ i ] ) ;
    return 0;
}
