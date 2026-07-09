#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in") ;
ofstream g("cmlsc.out");
int n , m , v[1025] , w[1025] , a[1025][1025] , sir[1025] , ma = 0 ;

int main()
{
    f >> n >> m ;
    for ( int i = 1 ; i <= n ; i ++ )
        f >> v[i] ;
    for ( int i = 1 ; i <= m ; i ++ )
        f >> w[i] ;
    for ( int i = 1 ; i <= n ; i ++ )
        for ( int j = 1 ; j <= m ; j ++ )
    {
        if ( v[i] == w[j] )
        {
           a[i][j] = 1 + a[i-1][j-1] ;
        }
        else
        {
            a[i][j] = max(a[i-1][j] , a[i][j-1] );
        }
    }
    int i , j ;
    for ( i = n ,  j = m ; i ; )
    {
        if ( v[i] == w[j] )
        {
            sir[++ma] = v[i] ; i -- ; j -- ;
        }
        else
            if ( a[i-1][j] < a[i][j-1] )
               j -- ;
            else
                i -- ;
    }
    g << ma << endl ;
    for (  i = ma ; i ; i -- )
        g << sir[i] << " " ;
    return 0;
}
