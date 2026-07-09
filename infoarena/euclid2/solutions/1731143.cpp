#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int a,b,x,i,t;
int main()
{
    f>>x;
    for(i=1;i<=x;i++)
    {
        f>>a>>b;
        while(b!=0)
        {
            t=b;
            b=a%b;
            a=t;
        }
        g<<a<<'\n';
    }
    return 0;
}
