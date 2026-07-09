// Simionescu Andrei, 2/18/2010
// http://infoarena.ro/problema/euclid2
// Dificultate: VERY EASY 
// Categorii: generic

#include <stdio.h>

int main(){
 freopen( "euclid2.in", "r", stdin );
 freopen( "euclid2.out", "w", stdout );
 
 int t, a, b;
 
 scanf( "%d", &t );
 
 while(t--)
    {
     scanf("%d %d", &a, &b);
     while( a && b )
        {
         if( a > b )
            a = a % b;
         else
            b = b % a;
        }
     printf( "%d\n", (a)?a:b );
    }
 
 return 0;
}
