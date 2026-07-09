#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,i,a,b;
int cmmdc(int x,int y)
{
    if(x==y)
        return x;
    else
        return cmmdc(y,y%x);
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
