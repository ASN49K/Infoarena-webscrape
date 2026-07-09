#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b,i,r;
int lnko(int a,int b)
{
    if(!b)
        return a;
    else
        return lnko(b,a%b);
}
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<lnko(a,b)<<endl;
    }
}
