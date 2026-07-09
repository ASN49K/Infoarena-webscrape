#include <fstream>
using namespace std;
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int cmmdc(int x, int y)
{
    int z;
    while(y!=0)
    {
        z=x%y;
        x=y;
        y=z;
    }
    return x;
}

int main()
{
    int i,t,a,b;
    in>>t;
    for(i=1;i<=t;i++)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
