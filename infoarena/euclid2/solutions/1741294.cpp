#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

inline int lnko (int a, int b)
{
    int r = 1;
    while (r != 0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int t, a, b, i;
int main()
{
    f >> t;
    for (i=1; i<=t; i++)
    {
        f >> a >> b;
        g << lnko(a, b) << "\n";
    }
}
