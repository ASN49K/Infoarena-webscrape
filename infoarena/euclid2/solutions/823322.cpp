#include <iostream>
#include <fstream>
using namespace std;
long long int tem,t,a,b,d,imp,r;
int main()
{
    ifstream ka("euclid2.in");
    ofstream ki("euclid2.out");
    ka>>t;
    for(int i=1;i<=t;i++)
    {
        ka>>a>>b;
        if(b>a)
        {
            a=tem;
            a=b;
            b=tem;
        }
        d=a;
        imp=b;
        r=d%imp;
        while(r!=0)
        {
            d=imp;
            imp=r;
            r=d%imp;
        }
        ki<<imp<<'\n';
    }
}
