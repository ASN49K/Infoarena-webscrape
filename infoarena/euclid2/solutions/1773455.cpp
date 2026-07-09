#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in") ;
ofstream g("euclid2.out") ;
int cmmdc ( int a , int b )
{
    while(a!= b )
    {
        if ( a > b )
            a = a - b ;
        else
            b = b - a ;
    }
    return a ;
}
int main()
{
    int n ;
    f >> n ;
    for ( int i = 1 ; i <= n ; i ++ )
    {
        int a , b ;
        f >> a >> b ;
        g << cmmdc(a,b) << endl ;
    }
    return 0;
}
