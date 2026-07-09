#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int gcd(unsigned long long x, unsigned long long y)
{
    if(y==0)return x;
    return gcd(y, x%y);
}
int main()
{
    unsigned long long t, x, y;
    in>>t;
    for(int i=1;i<=t;i++)
    {
        in>>x>>y;
        if(x<y)
        {
            unsigned long long aux=y;
            y=x;
            x=aux;
        }
        out<<gcd(x, y)<<'\n';
    }

    return 0;
}
