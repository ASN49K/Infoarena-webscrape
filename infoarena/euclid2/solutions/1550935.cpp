#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,t,i,r;
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        r=1;
        while(r)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<'\n';
    }
    return 0;
}
