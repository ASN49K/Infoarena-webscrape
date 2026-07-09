#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid2(int a, int b)
{
    if(b == 0)
        return a;
    return euclid2(b, a%b);
}

int main()
{
    int t,a,b;
    f>>t;
    for(int i=0; i<t; ++i)
    {
        f>>a>>b;
        g<<euclid2(a,b)<<'\n';
    }
}
