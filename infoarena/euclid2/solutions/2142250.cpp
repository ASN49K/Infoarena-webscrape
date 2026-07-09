#include <fstream>

typedef unsigned int uint;
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

uint n,a,b;

uint gcd ( uint a, uint b )
{
    uint r;

    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    ios::sync_with_stdio (false);

    fin >> n;

    for ( uint i = 0; i < n; ++i )
    {
        fin >> a >> b;

        fout << gcd(a,b) << '\n';
    }

    return 0;
}
