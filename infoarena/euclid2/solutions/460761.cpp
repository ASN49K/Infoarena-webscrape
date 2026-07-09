#include <iostream>
#include <fstream>

using namespace std ;

ifstream f ( "euclid2.in" ) ;
ofstream g ( "euclid2.out" ) ;

int nrPerechi ;

int calculEuclid ( int A , int B )
{
  if ( !B ) return A ;
  return calculEuclid ( B , A % B ) ;
}

int main ( )
{
  int a , b ;
  f >> nrPerechi ;
  for ( int i = 0 ; i < nrPerechi ; i++ )
  {
    f >> a >> b ;
    g << calculEuclid ( a , b ) << endl ;
  }
  return 0 ;
}
