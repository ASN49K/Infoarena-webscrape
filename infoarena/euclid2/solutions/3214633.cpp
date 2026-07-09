#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    f >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        f >> x >> y;
        while (y)
        {
            int r = x % y;
            y = x;
            x = r;
        }
        g << y << '\n';
    }
    f.close();
    g.close();
    return 0;
}
