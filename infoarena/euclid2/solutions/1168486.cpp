#include <fstream>
using namespace std;

ifstream is("euclid2.in");
ofstream os("euclid2.out");

int t, x, y;

int CMMDC();

int main()
{
    is >> t;
    while ( t-- )
    {
        is >> x >> y;
        os << CMMDC() << "\n";
    }
    is.close();
    os.close();
    return 0;
}

int CMMDC()
{
    if ( !y )
        return x;
    int rest;
    while ( y )
    {
        rest = x % y;
        x = y;
        y = rest;
    }
    return x;
}
