/* 
 * File:   main.cpp
 * Author: salexandru
 *
 * Created on January 13, 2011, 7:35 PM
 */
#include <cstdio>
#include <cstdlib>

using namespace std;

/*
 * 
 */
int gcd( int a, int b )
{
    int r=b;
    while( r )
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main(int argc, char** argv)
{
    int T, a, b;
    freopen( "euclid2.in", "rt", stdin );
    freopen( "euclid2.out", "wt", stdout );
    for( scanf("%d", &T); T; --T )
    {
        scanf( "%d%d", &a, &b );
        printf( "%d\n", gcd( a, b ) );
    }
    return 0;
}

