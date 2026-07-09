#include <iostream>
#include <fstream>

using namespace std;
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");

int main()
{
    int a,b,r;
    f>>a>>b;
    if(b==0)
    {
        g<<0;return 0;
    }
    while(b!=0)
    {
        r=a%b;a=b;b=r;
    }
    if(a==1)
        g<<0;
    else
        g<<a;

    return 0;
}
