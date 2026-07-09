#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a, int b)
{
    if(!b) return a;
    return euclid(b,a%b);
}
int n,a,b;
int main()
{
    f>>n;
    for(;n;n--)
    {
        f>>a>>b;
        g<<euclid(a,b)<<"\n";
    }
    return 0;
}
