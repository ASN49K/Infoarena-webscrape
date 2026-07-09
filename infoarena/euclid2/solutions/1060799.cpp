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
    int a,b;
    f>>a>>b;
    if(cmmdc(a,b)==1)g<<0;
    else g<<cmmdc(a,b);
    return 0;
}
