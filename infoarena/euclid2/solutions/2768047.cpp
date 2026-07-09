#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,r,T;
int main()
{
    f>>T;
    while(T)
    {
        f>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<'\n';

        T--;
    }
    return 0;
}
