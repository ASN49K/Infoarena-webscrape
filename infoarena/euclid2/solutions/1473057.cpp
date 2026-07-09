#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream f("euclid2.out");

int cmmdc (int x, int y)
{
    int r;
    r = 0;
    while (y)
    {
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}

int main ()
{
    int T, i;
    int a, b;
    f >> T;
    for (i=1; i<=T; i++)
    {
        f >> a >> b;
        g << cmmdc (a, b) << " ";
    }
    return 0;
}
