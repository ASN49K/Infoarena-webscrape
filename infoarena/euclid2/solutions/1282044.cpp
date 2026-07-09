#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream f("cmmdc.in");
    ofstream g("cmmdc.out");
    long unsigned int a,b;
    f>>a>>b;
    while(a!=b)
    {
        if(a>b)
            a-=b;
        else
            b-=a;
    }
    if(a==1)
    {
        g<<0;
        return 0;
    }
    else
        g<<a;

    return 0;
}
