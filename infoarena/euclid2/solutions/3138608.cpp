#include <fstream>
#include <map>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int m, n, maxi;
map<int, int> fr;

int cmmdc(int a, int b)
{
    while(b)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    f >> n;

    for(int i = 1; i <= n; i ++)
    {
        int x, y;
        f >> x >> y;

        g << cmmdc(x, y) << '\n';
    }
    return 0;
}
