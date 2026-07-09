#include <bits/stdc++.h>
#define ll long long
using namespace std ;
ifstream in ("euclid2.in") ;
ofstream out ("euclid2.out") ;
ll a , b ;
int n ;
ll euclid ( ll a , ll b )    {
    if ( !b )   return a ;
    return
    euclid( b , a % b ) ;
}
int main()  {
    in >> n ;
    while ( n -- )  {
    in >> a >> b ;
    out << euclid( a , b ) << '\n' , 0 ;
    }
}
