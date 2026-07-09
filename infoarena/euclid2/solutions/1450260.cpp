#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b)
{
    if (b)
        return cmmdc(b, a%b);
    else
        return a;
}

int main()
{
    int n, x, y, i;
    f >> n;
    for (i = 1; i <= n; i++)
    {
        f >> x >> y;
        g << cmmdc(x, y) << "\n";
    }
}
