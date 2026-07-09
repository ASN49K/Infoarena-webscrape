#include <fstream>

using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int euclid (int x, int y)
{
    if (y == 0)
        return x;
    return euclid (y, x % y);
}

int main()
{
    int i, T, x, y;
    f >> T;
    for (i = 1; i <= T; i++)
    {
        f >> x >> y;
        g << euclid (x, y) << "\n";
    }
    return 0;
}
