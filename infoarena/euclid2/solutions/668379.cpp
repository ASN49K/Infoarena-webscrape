#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int divx (int x, int y) {
    if (!y) return x;
    return divx( y, x%y);
    }

    int main ()
    {
        int t, a, b, x;
        f >> t;
        for ( ; t; --t)
        {
            f >> a >> b;

        g << divx(a,b) <<"\n";
        }
    }
