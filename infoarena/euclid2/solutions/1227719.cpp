#include <fstream>
#include <iostream>
using namespace std;
int y, x,  n;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int gcd(int a, int b)
{
    if(!b) return a;
    return gcd(b, a % b);
}
int main()
{
    int t;
    f>>t;
    while(t>0)
    {
        f>>x>>y;
        g<<gcd(x ,y)<<'\n';
        t--;
    }

return (0);
}
