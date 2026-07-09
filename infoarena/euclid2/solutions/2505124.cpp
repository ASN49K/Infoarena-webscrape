#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int t,a,b,r,i;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        while(a%b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<b<<'\n';
    }
    return 0;
}
