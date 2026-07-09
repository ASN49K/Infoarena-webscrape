#include <iostream>
#include <fstream>
using namespace std;

int gcd(int d, int i)
{
    while(i != 0)
    {
        int r = d % i;
        d = i;
        i = r;
    }
    return d;
}
int main()
{

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int t, x, y;
    f >> t;
    while(t --)
    {

        f >> x >> y;
        g << gcd(x, y) << "\n";
    }
    return 0;
}
