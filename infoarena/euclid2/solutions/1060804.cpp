#include <fstream>
using namespace std;
int cmmdc(int a,int b)
{if(b==0)return a;
 return cmmdc(b,a%b);
}
ifstream f("euclid.in");
ofstream g("euclid.out");
int main()
{
    int t,a,b;
    f>>t;
    for(int i=1;i<=t;i++)
    {f>>a>>b;g<<cmmdc(a,b);}
    return 0;
}
