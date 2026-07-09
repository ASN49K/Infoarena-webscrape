#include <iostream>
using namespace std;
#include<fstream>
const int NMAX = 100 ;
const int LOGNMAX = 7 ;
unsigned euclid (int a,int b)
{
    if (!b)
        return a;
    else
    euclid(b,a%b);
}

void rmq ( int rmq_father[ LOGNMAX ][ NMAX ], int rmq_edge [ LOGNMAX ][ NMAX ] , int Father [ NMAX ] , int Father_edge [ NMAX ] , int n )
    {
    int i , j ;
    for ( i = 1 ; i <= n ; ++ i )
    {
        rmq_father [ 0 ][ i ] = Father [ i ] ;
        rmq_edge [ 0 ][ i ] = Father_edge [ i ] ;
    }
    //rmq_edge [ i ][ j ] - muchia de cost minim dintre nodul j
    // si al 2 ^ i stramos al nodului j
    for ( i = 1 ; ( 1 << i ) <= n ; ++ i )
    for ( j = 1 ; j <= n ; ++ j )
    {
        rmq_father [ i ][ j ] = rmq_father [ i - 1 ][ rmq_father [ i - 1 ][ j ] ] ;
        rmq_edge [ i ][ j ] = min ( rmq_edge [ i - 1 ][ j ] , rmq_edge [ i - 1 ][ rmq_father [ i - 1 ][ j ] ] ) ;
    }
    }

    int query (  int rmq_father[ LOGNMAX ][ NMAX ], int rmq_edge [ LOGNMAX ][ NMAX ]  , int nod , int nr , int log )
    {
        int min_edge = - ( 1 << 30 ) ;
        while ( log --  )
        if ( ( ( 1 << log ) & nr )  )
        {
        min_edge = min ( rmq_edge [ log ][ nod ] , min_edge ) ;
        nod = rmq_father [ log ][ nod ] ;
        // pe masura ce urcam 2 ^ log nivele actualizam si min_edge cu
        //valoarea muchiei de cost minim de pe lant parcurs , daca e cazul
        }
        return min_edge ;
    }


int main ()
{
    int a,b,n;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    while(n)
    {
        f>>a>>b;
        g<<euclid(a,b)<<"\n";
        n--;
    }
    return 0;

}




