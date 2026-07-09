#include <iostream>
#include <fstream>
using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int t, n, x, s;

int main()
{
    f >> t;
    for (int i=1; i<=t; ++i)
    {
        f >> n;
        s=0;
        for (int j=1; j<=n; ++j)
        {
            f >> x;
            s^=x;
        }
        if (s)
        {
            g << "DA\n";
        }
        else
        {
            g << "NU\n";
        }
    }
    return 0;
}
