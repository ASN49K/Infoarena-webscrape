#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a,int b)
{
    int r;
    r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    int t,a,b;
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
