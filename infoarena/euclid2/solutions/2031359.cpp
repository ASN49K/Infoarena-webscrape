#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int a,b;

int main()
{
    int n;
    f>>n;
    while (n>0)
    {
        f>>a>>b;
        g<<__gcd(a,b);
        g<<"\n";
        n--;
    }
    return 0;
}
