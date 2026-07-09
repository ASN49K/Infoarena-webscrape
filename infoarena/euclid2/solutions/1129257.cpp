#include<fstream>
using namespace std;
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");
int a,b,r,t,i;
int main()
{
    f>>t;
    for(i=1;i<=t;++i)
    {
        f>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        if(a==1) g<<a<<'\n';
        else g<<a<<'\n';
    }
    g.close();
    return 0;
}
