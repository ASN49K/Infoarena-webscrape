#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

void euclid(long long a,long long b)
{
    int r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    g<<a<<'\n';
}
int main()
{
    long long n,i,a,b;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        euclid(a,b);
    }
    return 0;
}
