#include <iostream>
#include <fstream>



using namespace std;
ifstream f("euclid2.in" );
ofstream g("euclid2.out");


int cmmmdc(int a, int b)
{
    while ( a!=b )
    {
        if ( a>b ) a-=b;
        else b-=a;
    }
    return a;
}

int N,l,L;
int main()
{
    f>>N;
    for ( int i=1 ; i<=N ; i++ )
    {
        f>>l>>L;
        g<<cmmmdc(l,L)<<'\n';
    }
}
