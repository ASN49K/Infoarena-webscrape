#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T,a,b;

inline int gcd(int a,int b)
{
    if(!b)return a;
    else return gcd(b, a % b);
}
int main()
{
    f>>T;
    for(int i=1;i<=T;i++)
    {
        f>>a>>b;
        g<<gcd(a,b)<<'\n';
    }

    f.close();g.close();
    return 0;
}
