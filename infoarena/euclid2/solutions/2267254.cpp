#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,i,a,b,r;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        while(r!=0)
        {
           a=b;
           b=r;
           r=a%b;
        }
        g<<r<<'\n';
    }
    return 0;
}
