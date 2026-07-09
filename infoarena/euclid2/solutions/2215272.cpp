#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,T;

int cmmdc(int a,int b)
{
    if(a==0)
        return b;
    return cmmdc(b%a,a);
}

int main()
{
    f>>T;
    for(int i=1;i<=T;i++)
    {f>>a>>b;
    g<<cmmdc(a,b)<<"\n";}
    return 0;
}
