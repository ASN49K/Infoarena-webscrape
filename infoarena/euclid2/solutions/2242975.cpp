#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int a, b, n;

int cmmdc ( int a, int b )
{
    if ( !b ) return a;
    return cmmdc( b, a % b );
}

int main()
{
    fin >> n;
    for ( ; n > 0 ; n -- )
    {
        fin >> a >> b;
        fout << ( cmmdc ( a, b ) ) << '\n';
    }
}
