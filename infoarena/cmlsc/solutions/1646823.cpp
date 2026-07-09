#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in") ;
ofstream g("cmlsc.out") ;
int n , m  , i , j  , h = 0 , l = 0  ;
int main()
{
    f >> n >> m ;
    int a[n+1] , b[m+1] , k = 0 , c[m+1];
    for ( i = 1 ; i <= n ; i ++ )
    {
        f >> a[i];
    }
    for ( j = 1 ; j <= m ; j ++ )
        f >> b[j] ;
    for ( i = 1 ; i <= n ; i ++ )
    {
        for ( j = 1 ; j <= m ; j ++ )
            if ( a[i] == b[j] and j > k )
        {
            k = j ;
          c[h] = a[i] ;
            h ++ ;
        }
    }
    g << h << endl ;
    for ( i = 0 ; i < h ; i ++ )
        g << c[i] << " " ;
    return 0;
}
