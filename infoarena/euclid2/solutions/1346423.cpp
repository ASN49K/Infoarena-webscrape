#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T, x, y;

int main()
{
    f>>T;
    while (T--)
        f>>x>>y, g<<__gcd(x, y)<<'\n';
    return 0;
}
