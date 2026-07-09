#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long n,i,x,y;
long cmmdc(long a,long b)
{
    long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x>>y;
        g<<cmmdc(x,y)<<" "<<endl;
    }
    return 0;
}
