#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T, x, y;

int euclid(int x, int y)
{
    if (x>y) swap(x, y);
    if (x==0) return y;
    return euclid(y%x, x);
}

int main()
{
    f>>T;
    while (T--)
        f>>x>>y, g<<euclid(x, y)<<'\n';
    return 0;
}
