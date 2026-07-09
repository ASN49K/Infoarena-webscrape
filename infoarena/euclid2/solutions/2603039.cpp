#include <iostream>
#include <fstream>
using namespace std;
int t, d, i, r;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> t;
    for(; t; -- t)
    {
        f >> d >> i;
        while(i != 0)
        {
            r = d % i;
            d = i;
            i = r;
        }
        g << d << "\n";
    }
    return 0;
}
