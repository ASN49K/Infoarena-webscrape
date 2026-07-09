#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int T, a, b, r;
    f >> T;
    while (T--)
    {
        f >> a >> b;
        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        g << a << '\n';
    }
    f.close();
    g.close();
    return 0;
}
