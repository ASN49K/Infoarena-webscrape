#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,r,n,i;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        if(a<b)
        {
            a=a+b;
            b=a-b;
            a=a-b;
        }
        r=a%b;
        while(r>0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g<<b<<"\n";
    }
}
