#include <iostream>
#include <fstream>

using namespace std;

int gcd ( int a, int b ) {
   while ( b ) {
      int r = a % b;
      a = b;
      b = r;
   }
   return a;
}

ifstream fin ( "euclid2.in" );
ofstream fout ( "euclid2.out" );

int main()
{
   int n, x, y;
   fin >> n;
   for ( int i = 1; i <= n; i ++ )
      fin >> x >> y, fout << gcd ( x, y ) << '\n';
    return 0;
}
