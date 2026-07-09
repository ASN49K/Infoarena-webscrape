#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long n,i,x,y;
long cmmdc(long a,long b)
{
    if(b==0)
        return a;
    return cmmdc(b,a%b);
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
