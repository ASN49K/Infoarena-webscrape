#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int main ()
    {
        int t, a, b, j, i, x;
        f >> t;
        for ( j=1; j<=t; j++)
        {
            f >> a >> b;
            for ( i=1; i<=min(a,b); i++ )
            {
                if ((a % i==0) && (b % i==0)) x = i;

            }
        g << x <<"\n";
        }
    }
