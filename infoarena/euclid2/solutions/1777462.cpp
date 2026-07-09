#include <fstream>
using namespace std;

const string fis = "euclid2";
ifstream is(fis + ".in");
ofstream os(fis + ".out");

int main()
{
    int t, a, b, rest;
    is >> t;
    while ( t-- )
    {
        is >> a >> b;
        while ( b )
        {
            rest = a % b;
            a = b;
            b = rest;
        }
        os << a << "\n";
    }
    is.close();
    os.close();
    return 0;
}
