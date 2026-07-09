#include <iostream>
#include <fstream>

using namespace std;

ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

int t,a,b;

int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a%b);
}

int main()
{
    fi>>t;
    for(int i=1; i<=t; i++)
    {
        fi>>a>>b;
        fo<<gcd(a,b)<<endl;
    }
}
