#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b)
{
    int c;
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
    int T, i, a, b;

    f>>T;
    for(i=1; i<=T; i++)
    {
        f>>a>>b;

        g<<cmmdc(a, b)<<"\n";
    }

    f.close();
    g.close();
    return 0;
}
