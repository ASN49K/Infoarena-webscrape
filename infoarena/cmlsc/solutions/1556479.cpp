#include <cstdio>
#include <algorithm>

using namespace std;

short int d[1030][1030] , a[1030] , b[1030] ;

void scriere ( int x , int y )
{
    if( x > 0  and y > 0 )
    {
        if( a[x] == b[y] )
        {
            scriere( x-1 , y-1 );
            printf("%d ",a[x]);
        }
        else
        {
            if( d[x-1][y] > d[x][y-1] )
                scriere( x - 1 , y ) ;
            else
                scriere( x , y - 1  ) ;
        }
    }
}

int main()
{
    freopen("cmscl.in","r",stdin);
    freopen("cmscl.out","w",stdout);
    int n , m ;
    scanf("%d %d",&m,&n);
    for ( int i = 1 ; i <= m ; i++ )
    {
        scanf("%d ",&a[i]);
    }
    for ( int i = 1 ; i <= n ; i++ )
    {
        scanf("%d ",&b[i]);
    }
    for ( int i = 1 ; i <= m ; i++ )
    {
        for ( int j = 1 ; j <= n ; j++ )
        {
            if ( i == 0 || j == 0 )
            {
                d[i][j] == 0 ;
            }
            else
            if ( a[i] == b[j] ) d[i][j] = d[i-1][j-1] + 1 ;
            else d[i][j] = max( d[i-1][j] , d[i][j-1] ) ;
        }
    }
    printf("%d\n",d[m][n]);
    scriere(m,n);
    return 0 ;
}
