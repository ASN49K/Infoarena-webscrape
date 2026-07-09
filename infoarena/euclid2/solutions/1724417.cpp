
#include <iostream>
#include <fstream>

using namespace std;

ifstream in( "cmmdc.in" ) ;
ofstream out( "cmmdc.out" ) ;

int cmmdc( int a , int b ) 
{
    int r ;
    
    while( a )
    {
        r = b % a ;
        b = a ;
        a = r ;
    }
    
    if( b == 1 )
        return 0 ;
    else
        return b;
}

int main() {
    
    int a , b ;
    
    in >> a ;
    in >> b ;
    
    out << cmmdc( a, b ) ;

    return 0;
}

