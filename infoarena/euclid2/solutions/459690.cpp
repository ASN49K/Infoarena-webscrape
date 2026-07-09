#include <cstdlib>
#include <fstream>

/*
 *
 */
 using std::ifstream;
 using std::ofstream;
 typedef unsigned int u;
 inline u gcd( u a, u b )
 {
     static u r;
     while( b )
     {
         r=a%b;
         a=b;
         b=r;
     }
     return a;
 }
 int main( void )
 {
     u N, a, b;
     ifstream in( "euclid2.in" );
     ofstream out( "euclid2.out" );
     for( in>>N; N; --N )
     {
         in>>a>>b;
         out<<gcd( a, b )<<'\n';
     }
     return EXIT_SUCCESS;
 }
