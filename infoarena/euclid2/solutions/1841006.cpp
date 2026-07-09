#include <fstream>
#include <cmath>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b)
{
    int r1;
    if (a < b)
    {
        int aux = a;
        a = b;
        b = aux;
    }
    do
    {
        r1 = a % b;
        a = b;
        b = r1;
    } while (r1);
    return a;
}

int main()
{
    int a, b, t;
    f >> t;
    for (int i = 0; i < t; ++i)
    {
        f >> a >> b;
        g << cmmdc(a, b) << "\n";
    }
    f.close();
    g.close();
    return 0;
}
