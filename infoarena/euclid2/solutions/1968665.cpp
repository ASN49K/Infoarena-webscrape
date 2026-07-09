#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,R,n;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>a>>b;
        while(b>0)
        {
            R=a%b;
            a=b;
            b=R;
        }
        g<<a<<'\n';
    }
    return 0;
}
