#include <iostream>
#include <fstream>
using namespace std;
long long a,b,r;
int t,i;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    f>>t;
    for (i=1; i<=t; i++)
    {
        f>>a>>b;
        r=a%b;
        while (r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g<<b<<'\n';
    }
    return 0;
}
