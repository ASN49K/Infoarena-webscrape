#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,i,r,a,b;
int divi(int a,int b,int x)
{
    if(x==0) return b;
    divi(b,x,a%b);
}
int main()
{
    f>>n;
    for(i=1;i<=n;++i)
    {
         f>>a>>b;
         r=a%b;
         g<<divi(a,b,r)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
