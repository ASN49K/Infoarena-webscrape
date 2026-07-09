#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in") ;
ofstream g("euclid2.out") ;
int cmmdc (int a,int b)
{ int c ;
    if (a%b == 0 )
        c= b ;
    else
        c = cmmdc(b , a%b ) ;
    return c ;
}
int main()
{
    int n , m , t ;
    f >> t ;
    for ( int i = 1 ; i <= t ; i ++ )
    {
        f >> n >> m ;
        g << cmmdc (m,n) << endl ;
    }

    return 0;
}
