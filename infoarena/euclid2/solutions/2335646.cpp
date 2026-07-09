#include <iostream>
#include <fstream>

using namespace std;

ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

unsigned long eu(unsigned long a, unsigned long b)
{
    if(!b)
        return a;
    return eu( b , a%b );
}

int main()
{
    unsigned long n;

    fi>>n;

    for( unsigned long i=0 ; i<n ; i++ )
        {unsigned long x,y;
        fi>>x>>y;
        fo<<eu(x,y);}

    return 0;
}
