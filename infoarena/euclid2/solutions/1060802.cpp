#include <fstream>

using namespace std;
int cmmdc(int a,int b)
{while(a!=b)if(a>b)a-=b;else b-=a;
return a;
}
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");
int main()
{
    int a,b,t;
    f>>t;
    for(int i=1;i<=t;i++)
    {f>>a>>b;
    g<<cmmdc(a,b)<<endl;}
    return 0;
}
