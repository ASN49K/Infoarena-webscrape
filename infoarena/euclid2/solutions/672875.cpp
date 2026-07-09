#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned t,a,b,i;
void cmmdc(unsigned a, unsigned b)
{ unsigned r;
    r=a%b;
    while(r)
    {
        a=b;b=r;r=a%b;
    }
    g<<b<<'\n';
}
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        cmmdc(a,b);
    }
    g<<'\n';
    return 0;
}
