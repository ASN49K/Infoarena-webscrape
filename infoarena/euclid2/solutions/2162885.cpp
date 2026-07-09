#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,a,b,r,i;
int main()
{
    f>>n;
    for(i=1;i<=n;++i)
    {
        f>>a>>b;
        if(a<b) swap(a,b);
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<"\n";
    }
}
