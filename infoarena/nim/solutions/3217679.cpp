#include <iostream>
#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");

int t, n, sol;

int main()
{
    f >> t;
    for (int i = 1; i <= t; ++i)
    {
        f >> n;
        sol = 0;
        for (int j = 1; j <= n; ++j)
        {
            int x;
            f >> x;
            sol ^= x;
        }
        if (sol)
        {
            g << "DA" << '\n';
        }
        else
            g << "NU" << '\n';
    }
    return 0;
}