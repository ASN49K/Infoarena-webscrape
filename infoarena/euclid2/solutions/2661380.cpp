#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t, D, I, rest;

int main()
{
    f >> t;

    while(t --)
    {
        f >> D >> I;

        while(I != 0)
        {
            rest = D % I;
            D = I;
            I = rest;
        }

        g << D << "\n";
    }

    return 0;
}
