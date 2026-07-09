#include <fstream>
using namespace std;

int t, n, x, s;

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{   f>>t;
    for (; t; --t)
    {   f>>n;
        s=0;
        for (; n; --n)
        {   f>>x;
            s=s^x;
        }
        if (s)
            g<<"DA\n";
        else
            g<<"NU\n";
    }
    return 0;
}
