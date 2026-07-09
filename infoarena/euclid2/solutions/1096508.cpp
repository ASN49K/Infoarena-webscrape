#include <iostream>
#include <fstream>

using namespace std;
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");

int a,b,r,aux,i,n;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        if(a<b) {aux=a;a=b;b=aux;}
        r=a%b;
        while(r>0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g<<b<<'\n';
    }
    return 0;
    f.close();
    g.close();
}
