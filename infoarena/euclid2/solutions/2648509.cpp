#include<fstream>
using namespace std;
long long n,x,y;
long long cmmdc(long long x,long long y)
{
    while(x!=y)
        if(x>y)
        x/=y;
    else
        y/=x;
    return x;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x>>y;
        g<<cmmdc(x,y)<<endl;
    }
    f.close();
    g.close();
    return 0;
}
