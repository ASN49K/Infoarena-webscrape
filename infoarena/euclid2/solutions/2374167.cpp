#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a, b, t;
void cmmdc(int x, int y)
{
    int r;
    while (y)
    {
        r = x % y;
        x = y;
        y = r;
    }
    g<<x<<"\n";
}
int main()
{
    f>>t;
    for (int i = 1; i <= t; ++i)
    {
        f>>a>>b;
        cmmdc(a, b);
    }
}
