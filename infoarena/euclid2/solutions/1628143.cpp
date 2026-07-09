#include<iostream>
#include<string.h>
#include <fstream>

using namespace std;

ifstream f("euclid.in");
ofstream g("euclid.out");

int GCD( int a, int b )
{
    if(!b)
        return a;
    return GCD( b, a%b );
}

int main()
{
    int nr1, nr2 , x;

    f >> x;
    for( int i = 1; i<=x; i++ )
    {
        f >> nr1 >> nr2;
       g <<  GCD( nr1, nr2 ) << "\n";
    }
    f.close();
    g.close();


    return 0;

}

