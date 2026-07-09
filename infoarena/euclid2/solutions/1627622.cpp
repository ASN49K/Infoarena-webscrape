#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(long x,long y)
{
    if(x!=y)
    {
        if(x>y)
            return cmmdc(x-y,y);
        else
            if(x<y)
            return cmmdc(x,y-x);
    }

    return x;
}

int main()
{
    long T,a,b;

    fstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>T;
    for(int i=1;i<=T;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<"\n";

    }
    f.close();
    g.close();
    return 0;
}
