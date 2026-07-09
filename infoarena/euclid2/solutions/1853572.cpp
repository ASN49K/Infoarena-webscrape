#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T,a,b,cmmdc(int,int);
int main()
{f>>T;
for(int i=1;i<=T;i++)
{ f>>a>>b;
g<<cmmdc(a,b)<<endl;}

    return 0;
}
int cmmdc(int a, int b)
{
    int t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
    if(b==0)
        return a;
}
