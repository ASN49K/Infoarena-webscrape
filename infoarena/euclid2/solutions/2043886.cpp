#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned long long a,b,t,i;
int main()
{
    f>>t;
    for(i=1; i<=t; i++)
    {
        f>>a>>b;
        while(a!=0&&b!=0)
        {
            if(a>b) a=a%b;
            else b=b%a;
        }
        if(a!=0)
            g<<a<<'\n';
        else
            g<<b<<'\n';
    }
    return 0;
}
