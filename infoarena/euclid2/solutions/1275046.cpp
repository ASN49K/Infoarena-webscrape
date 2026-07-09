#include <iostream>
#include <fstream>
using namespace std;

int main()
{   int n,a,b,t,r,i;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
     f>>t;
    for(i=1;i<=t;i++)
        f>>a>>b;
        r=a%b;
        while(n)
    {
        a=b;
        b=r;
        r=a%b;
    }
    g<<b;

    return 0;
}
