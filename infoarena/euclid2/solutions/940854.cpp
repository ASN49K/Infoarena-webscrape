#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

void cmmdc(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    g<<a<<"\n";
}

int t,a,b;

int main()
{
    f>>t;
    for(int i=1;i<=t;i++) {f>>a>>b;cmmdc(a,b);}

    f.close();
    g.close();
    return 0;
}
