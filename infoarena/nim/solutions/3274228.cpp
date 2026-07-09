#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int n, a[10005];

void solv()
{
    f >> n;
    for(int i = 1; i <= n; i ++)
        f >> a[i];

    int xr = 0;
    for(int i = 1; i <= n; i ++)
        xr = (xr^a[i]);

    g << (xr > 0 ? "DA" : "NU") << '\n';
}

int main()
{
    int t; f >> t;
    for(; t >= 1; t --)
        solv();
    return 0;
}
