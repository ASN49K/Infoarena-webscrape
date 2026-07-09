#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b)
{
    if (b == 0) return a;
    return euclid(b, a % b);
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