#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int a,b,t,i;

int euclid(int a, int b)
{
    int r=0;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{

    f>>t;
    for(i=1;i<=t;++i)
        f>>a,f>>b,g<<euclid(a,b)<<'\n';

    return 0;
}
