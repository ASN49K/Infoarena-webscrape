#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    long long t,i,a,b,r;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        while(b!=0)
        {
            r=b%a;
            a=b;
            b=r;
        }
        g<<a<<"\n";
    }
    return 0;
}
