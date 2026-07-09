#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n, a, b;

void euclid( int a, int b )
{
    int r = a % b;

    while ( r )
    {
        a = b;
        b = r;
        r = a % b;
    }

    g << b << '\n';
}

int main()
{
    f >> n;

    while ( n-- )
    {
        f >> a >> b;
        euclid( a, b );
    }
    return 0;
}
