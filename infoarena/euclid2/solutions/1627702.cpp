#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(long x,long y)
{
    if(y!=0)
        return x;
    return cmmdc(y,x%y);
}

int main()
{
    long T,a,b;

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>T;
    for(int i=1;i<=T;i++)
    {
        f>>a>>b;
        if(a<b)
            g<<cmmdc(a,b)<<"\n";
        else
            g<<cmmdc(b,a)<<"\n";

    }
    f.close();
    g.close();
    return 0;
}
