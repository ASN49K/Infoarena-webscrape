#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out") ;
int n , m , i , j , j2 ;
int main()
{
    f >> n >> m ;
    int a[n+1] , b[m+1] , c[1001] , k = 0 ;
    for ( i = 1 ; i <= n ; i ++ )
        f >> a[i] ;
    for ( i = 1 ; i<= m ; i ++ )
        f >> b[i] ;
        j2 = 1 ;
    for ( i = 1 ; i <= n ; i ++ )
        for ( j = j2 ; j <= m ; j ++ )
        if ( a[i] == b[j] )
        {
            k ++ ;
            c[k] = a[i] ;
           j2 = j ;
        }
        g << k << endl ;
        for ( i = 1 ; i <= k ; i ++ )
            g << c[i] << " ";
        return 0 ;
}
