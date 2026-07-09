#include <iostream>
#include <fstream>

using namespace std;

long long gcd(long long a, long long b)
{
    if(a==0)
        return b;
    else
        return gcd(b%a,a);
}

int main()
{
    ifstream in ("euclid2.in");
    ofstream out ("euclid2.out");

    long long x,y;
    int t;
    in>>t;
    for(int i=0;i<t;i++)
    {
        in>>x>>y;
        out<<gcd(x,y)<<"\n";
    }
    return 0;
}
