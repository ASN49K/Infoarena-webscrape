#include <fstream>

using namespace std;
int t;
long long a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(long long x,long long y)
{
    int r;
    do
    {
        r=x%y;
        x=y;
        y=r;
    } while (r!=0);
    return x;
}
void citire (long long a,long long b)
{
    f>>a;
    f>>b;
    g<<cmmdc(a,b)<<'\n';
    t--;
    if (t>0) citire(a,b);
}
int main()
{  f>>t;
    citire(a,b);
    return 0;
}
