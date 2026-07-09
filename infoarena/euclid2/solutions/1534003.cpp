#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int i;
long T,r,a,b;
int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b); }
int main()
{
    f>>T;
    for(i=0;i<T;i++)
    {
        f>>a; f>>b;
        g<<gcd(a,b)<<endl;
    }
    return 0;
}
