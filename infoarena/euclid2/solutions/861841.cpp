#include <fstream>
using namespace std;

fstream f("euclid2.in",ios::in), g("euclid2.out" , ios::out);

long long cmmdc(long long a, long long b)
{
    if (!b) return a;
    else return cmmdc(b,a%b);
}

int main()
{
    int t;
    long long a,b;
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
