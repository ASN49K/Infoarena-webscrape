#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int CMMDC(int a, int b)
{
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int a, b, t, i;
    f >> t;
    for (i = 1; i <= t; i++)
    {
        f >> a >> b;
        g << CMMDC(a, b) << "\n";
    }
    return 0;
}