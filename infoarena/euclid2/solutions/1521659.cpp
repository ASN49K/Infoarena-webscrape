#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long cmmdc(long long a,long long b)
{
    if(!b)
        return a;
    return cmmdc(b,a%b);
}
int main()
{
    int n,i;
    long long a,b;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<"\n";

    }
    f.close();
    g.close();
    return 0;
}
