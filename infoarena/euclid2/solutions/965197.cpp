#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main ()
{
    int a,b,r,t;
    f>>t;
    while (t--)
    {
        f>>a>>b;
        r=a%b;
        while (r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        if (b==1) g<<0;
        else g<<b<<'\n';
    }
}
