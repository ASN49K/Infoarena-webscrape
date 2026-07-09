#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int t,a,b,i,r,c1,c2,aux,d;
    f>>t;
    for (i=1;i<=t;++i)
    {
        f>>a>>b;
        if(a>b)
        {
            c1=a;
            c2=b;
        }
        if(a<b)
        {
            c1=b;
            c2=a;
        }
        r=c2;
        while(r!=0)
        {
            r=c1%c2;
            d=c1/c2;
            c1=c2;
            c2=d;
        }
        g<<c1<<endl;
    }
    f.close();
    g.close();
return 0;
}
