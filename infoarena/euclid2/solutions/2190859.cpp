#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,i;
int a,b,r;
int cmmdc(int a, int b)
{
r=0;
    while(r!=1)
    {   r=a%b;
        a=b;
        b=r;
    }
    return b;
}
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
