#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");

int t,n,a,xorsum;

int main()
{
    f>>t;
    for (int i = 1; i <= t; i++)
    {
        f >> n;
        xorsum = 0;

        for (int j = 1; j <= n; ++j)
        {
            f >> a;
            xorsum ^= a;
        }

        if (xorsum == 0)
            g << "NU" << '\n';
        else g << "DA" << '\n';
    }

    f.close();
    g.close();
    return 0;
}
