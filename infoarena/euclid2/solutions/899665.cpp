#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int t,a,b,i,r,aux,d;
    bool ok;
    f>>t;
    for (i=1;i<=t;i++)
    {
        f>>a>>b;
        if(b>a)
        {
            aux=a;
            a=b;
            b=aux;
        }
        r=a%b;
        ok=0;
        while(r!=0)
        {
            ok=1;
            r=a%b;
            a=b;
            b=r;
        }
        if(ok==1)
            g<<a<<"\n";
        if(ok==0)
            g<<b<<"\n";
    }
    f.close();
    g.close();
    return 0;
}
