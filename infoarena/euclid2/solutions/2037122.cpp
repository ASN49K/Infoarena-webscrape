#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int i,t,a,b,r;
int main()
{f>>t;
for(i=1;i<=t;i++)
{
    f>>a>>b;
    if(a>b)
    {
        r=a%b;

        while(r!=0)
        {
        a=b;
        b=r;
        r=a%b;
        }
        g<<b<<'\n';
    }
    else
    {
        r=b%a;

        while(r!=0)
        {
        b=a;
        a=r;
        r=b%a;
        }
        g<<a<<'\n';
    }
}
    return 0;
}
