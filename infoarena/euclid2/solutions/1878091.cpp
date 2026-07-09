#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

unsigned euclid(unsigned a,unsigned b)
{
    if(!b) return a;
    else return euclid(b,a%b);
}

int main()
{
    unsigned T,a,b;
    f>>T;
    while(T--)
    {
        f>>a>>b;
        g<<euclid(a,b)<<endl;
    }
    f.close();
    g.close();
    return 0;
}
