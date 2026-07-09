#include <iostream>
#include <fstream>
using namespace std;

int a,b;

int euclid(int a, int b)
{
    if (!b) return a;
    return euclid(b, a % b);
}

int main()
{
    int t;
    fstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(int i=1;i<=t;++i)
    {
    f>>a>>b;
    g<<euclid(a,b);
    }
}
