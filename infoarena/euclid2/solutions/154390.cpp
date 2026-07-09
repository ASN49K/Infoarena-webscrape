#include <stdio.h>

long long a, b, n;


void cmmdc()
{
   long long r;

   while (b)
   {
      r = a % b;
      a = b;
      b = r;
   }

   printf( "%lld\n", a );
}

int main()
{
   long long i;

   freopen( "euclid.in", "rt", stdin );
   freopen( "euclid.out", "wt", stdout );

   scanf( "%lld", &n );

   for (i=0; i<n; i++)
   {
      scanf( "%lld %lld", &a, &b );
      cmmdc();
   }

   return 0;
}