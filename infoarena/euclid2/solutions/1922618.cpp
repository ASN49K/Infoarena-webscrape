#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid( int a, int b )
{
    int r = a % b;

    while ( r )
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main()
{
    int n, a, b;

    f >> n;

    while ( n )
    {
        f >> a >> b;

        g << euclid( a, b ) << endl;

        n --;
    }

    return 0;
}
