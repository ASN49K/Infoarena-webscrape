#include <fstream>
#include <iostream>

using namespace std;

ifstream f("ciur.in");
ofstream g("ciur.out");

int a,b,c,t,i;
int main()
{
    f>>t;
    for(i=t;i>0;--i)
    {
        f>>a>>b;
        while(b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        g<<a;
    }
    return 0;
}
