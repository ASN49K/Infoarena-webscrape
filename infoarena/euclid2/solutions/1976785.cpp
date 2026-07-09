#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int i,t,a,b,r;
int main()
{
    f>>t;
    for(i=1; i<=t; i++)
    {
        f>>a>>b;
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g<<b<<endl;
    }
    f.close();
    g.close();
}
