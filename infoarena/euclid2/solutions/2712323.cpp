#include <iostream>
#include <fstream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int t, a, b;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> t;
    for (int i = 0; i < t; i++)
    {
        f >> a >> b;
        g << gcd(a, b) << "\n";
    }
    return 0;
}