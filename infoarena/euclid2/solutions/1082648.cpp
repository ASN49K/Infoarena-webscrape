#include <iostream>
#include <fstream>
using namespace std;

int main()
{int t,a,b,i,r;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
for (i=1;i<=t;i++)
{
    f>>a>>b;
    while (b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    g<<a;
}

    return 0;
}
