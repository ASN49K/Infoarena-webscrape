#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    long T,a,b,i,r;
    f>>T;
    for (i=1; i<=T; i++)
    {
        f>>a>>b;
        r=a%b;
        while(r!= 0)
        {
           a=b;
           b=r;
           r=a%b;
        }
        g<<b<<'\n';
    }
    return 0;
}
