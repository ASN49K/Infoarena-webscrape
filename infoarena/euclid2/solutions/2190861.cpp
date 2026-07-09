#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,i;
int a,b;
int cmmdc(int a, int b)
{
int r;
    while(r!=0)
    {   r=a%b;
        a=b;
        b=r;
    }
    return a;
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
