#include <fstream>
using namespace std;

ifstream is("euclid2.in");
ofstream os("euclid2.out");

int T;
long long int a, b, c;

void Euclid( long long int a,long long int b, long long int& c );

int main()
{
    is >> T;
    for ( int i = 0; i < T; i++ )
    {
        is >> a >> b;
        Euclid( a, b, c );
        os << c << '\n';
    }

    is.close();
    os.close();
    return 0;
}

void Euclid( long long int a,long long int b, long long int& c )
{
    int rest;
    while ( b )
    {
        rest = a % b;
        a = b;
        b = rest;
    }
    c = a;
}
