#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cm(int a,int b)
{
    int x;
    x=a%b;
    while(x!=0)
    {
        a=b;
        b=x;
        x=a%b;
    }
    return b;
}
int main()
{
    int t,a,b,i;
    f>>t;
    for(i=0;i<t;++i)
    {
        f>>a>>b;
        g<<cm(a,b)<<"\n";
    }
}
