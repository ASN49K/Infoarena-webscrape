#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,t,T;

int cmmdc(int a, int b)
{
    if(a==0) return b;
    else
    {
        return cmmdc(b%a,a);
    }
}

int main()
{
    f>>T;
    for(t=1;t<=T;t++)
    {
        f>>a>>b;
        if(a>b) swap(a,b);
        g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
