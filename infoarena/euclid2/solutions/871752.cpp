#include<iostream>
#include<fstream>
using namespace std;
ifstream f;
ofstream g;
int main()
{
    int i,a,b,t,r,x,y;
    f.open("euclid2.in");
    g.open("euclid2.out");
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>x>>y;
        a=x;
        b=y;
        r=1;
        while(r!=0)
        {

            r=a%b;
            a=b;
            b=r;
        }
        g<<b<<endl;
    }
    f.close();
    g.close();
}
