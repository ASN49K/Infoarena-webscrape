#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,i,a,b,r;
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        /*while(a!=b)
        {
            if(a>b)
                a-=b;
            else
                b-=a;
        }*/
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g<<b<<"\n";
    }
    f.close();
    g.close();
    return 0;
}
