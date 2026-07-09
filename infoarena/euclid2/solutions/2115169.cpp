#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned long long n,i,x,y,r;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x>>y;
        r=x%y;
        while(r!=0)
        {
            x=y;
            y=r;
            r=x%y;
        }
        g<<y<<'\n';
    }
    return 0;
}
