#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,i;
int a,b;
int divi(int a,int b,int r)
{
    if(r==0) return b;
    div(b,r,a%b);
}
int main()
{
    f>>n;
    for(i=1;i<=n;++i)
    {
         f>>a>>b;
         g<<divi(a,b,a%b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
