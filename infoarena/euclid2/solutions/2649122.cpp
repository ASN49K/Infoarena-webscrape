#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t;

int gcd(int a, int b)
{   if(!b) return a;
    return gcd(b, a % b);
}

int main()
{
    f >> t;
    while(t--)
        {   int a, b;
            f >> a >> b;
            g << gcd(a, b) << '\n';
        }
    return 0;
}
