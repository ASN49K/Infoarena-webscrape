#include <iostream>
#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int main()
{
    int t, n, xors, objects;
    f >> t;
    while (t--)
    {
        f >> n;
        xors = 0;
        for (int i = 1; i <= n; i++)
        {
            f >> objects;
            xors = xors ^ objects;
        }
        if (xors != 0) g << "DA\n";
        else g << "NU\n";
    }
    return 0;
}
