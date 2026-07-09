#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b)
{
    if (a == 0) return b;
    else if (b == 0) return a;
    while (a != b)
    {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

int main()
{
    int n, x, y;
    in >> n;
    for (int i = 1; i <= n; i++)
    {
        in >> x >> y;
        out << euclid(x, y) << '\n';
    }
    return 0;
}