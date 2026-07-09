#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int x, y, nrquiz;

int cmmdc(int a, int b)
{
    if (b == 0)
        return a;
    return cmmdc(b, a % b);
}

int main()
{
    f >> nrquiz;

    while (nrquiz)
    {
        nrquiz --;
        f >> x >> y;
        g << cmmdc(x, y) << '\n';
    }
    return 0;
}
