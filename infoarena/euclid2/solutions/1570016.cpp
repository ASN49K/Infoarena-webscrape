#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n,a,b,r,i;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        if(a>b) r=a%b;
        else r=b%a;
        while(r!=0)
        {
            a=b;
            b=r;
            if(a>b) r=a%b;
            else r=b%a;
        }
        g<<b<<"\n";
    }
    return 0;
}
