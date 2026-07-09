#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

unsigned euclid(unsigned a,unsigned b)
{
    unsigned c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    unsigned T,a,b,i;
    f>>T;
    for(i=1; i<=T; i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<endl;
    }
    f.close();
    g.close();
    return 0;
}
