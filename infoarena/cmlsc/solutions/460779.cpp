#include <fstream>
#include <iostream>

using namespace std ;

const int MAXN = 1025 ;

ifstream f ( "cmlsc.in" ) ;
ofstream g ( "cmlsc.out" ) ;

int subsirComun [ MAXN ] [ MAXN ] ;
int A [ MAXN ] , B [ MAXN ] , subSir [ MAXN ] ;
int lenA , lenB ;

int max ( int Linie , int Coloana )
{
  if ( subsirComun [ Linie - 1 ] [ Coloana ] > subsirComun [ Linie ] [ Coloana - 1 ] )
    return subsirComun [ Linie - 1 ] [ Coloana ] ;
  return subsirComun [ Linie ] [ Coloana - 1 ] ;
}

void citireFisier ( )
{
  f >> lenA >> lenB ;
  for ( int i = 1 ; i <= lenA ; ++i )
    f >> A [ i ] ;
  for ( int i = 1 ; i <= lenB ; ++i )
    f >> B [ i ] ;
}

void construireMatrice ( ) 
{
  for ( int i = 1 ; i <= lenA ; ++i )
  {
    for ( int j = 1 ; j <= lenB ; ++j )
    {
      if ( A [ i ] == B [ j ] )
      {
	subsirComun [ i ] [ j ] = subsirComun [ i - 1 ] [ j - 1 ] + 1 ;
      }
      else 
	subsirComun [ i ] [ j ] = max ( i , j ) ;
    }
  }
}

int main ( ) 
{
  citireFisier ( ) ;
  construireMatrice ( ) ;
  g << subsirComun [ lenA ] [ lenB ] << endl ;
  int i = 0 ;
  while ( subsirComun [ lenA ] [ lenB ] )
  {
    while ( subsirComun [ lenA ] [ lenB ] == subsirComun [ lenA ] [ lenB - 1 ] )
      -- lenB ;
    while ( subsirComun [ lenA ] [ lenB ] == subsirComun [ lenA - 1 ] [ lenB ] )
      -- lenA ;
    subSir [ ++i ] = A [ lenA ] ;
    -- lenA ;
    -- lenB ;
  }
  for ( int j = i ; j > 0 ; -- j )
    g << subSir [ j ] << " " ;
  return 0 ;
}
