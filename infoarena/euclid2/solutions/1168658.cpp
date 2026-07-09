#include <fstream>
#define fr(i,x) for (i=1;i<=x;i++)
using namespace std;
int a,b,T,i;
int cmmdc(int a,int b)
{
    int c=0;
    while (b) c=a%b,a=b,b=c;
    return a;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    fr(i,T)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
