#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main()
{
    long long a,b;
    int t,i;
    f >> t;
    for (i = 0; i < t; i++)
    {
        f >> a >> b;
        g << gcd(a,b) << endl;
    }
    f.close();
    g.close();
}
