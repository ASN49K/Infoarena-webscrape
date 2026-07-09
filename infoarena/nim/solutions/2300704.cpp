#include <cstdio>

#define MAXN 10000

using namespace std;

int v[MAXN+5];

int main()
{
  freopen( "nim.in", "r", stdin );
  freopen( "nim.out", "w", stdout );

  int t;

  scanf( "%d", &t );

  while( t )
  {
    int n, sumxor=0;

    scanf( "%d", &n );

    for( int i=1;i<=n;i++ )
    {
      scanf( "%d", &v[i] );
      sumxor^=v[i];
    }

    if( sumxor )
      printf( "DA\n" );
    else
      printf( "NU\n" );

    t--;
  }

  return 0;
}
