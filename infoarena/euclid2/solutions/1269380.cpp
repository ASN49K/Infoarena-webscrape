#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long long cmmdc(long long x, long long y)
{
    while(x!=0 && y!=0)
        if(x>y)
            x=x%y;
        else
            y=y%x;
    return x+y;
}

int T,i;
long long x,y;
int main()
{
    f>>T;
    for(i=1;i<=T;i++)
        {
            f>>x>>y;
            g<<cmmdc(x,y)<<"\n";
        }
}
