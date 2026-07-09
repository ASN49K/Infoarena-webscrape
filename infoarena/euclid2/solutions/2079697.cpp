#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmmdc.in");
ofstream g("cmmdc.out");

int cmmdc(int a,int b)
{
    if(a==0 && b!=0)
        return b;
    if(a!=0 && b==0)
        return a;
    if(a==b)
        return a;
    if(a>b)
    {
        return cmmdc(a-b,b);
    }
    else
    {
        return cmmdc(a,b-a);
    }
}

int main()
{
    int a,b;

    f>>a>>b;
    g<<cmmdc(a,b);

    f.close();
    g.close();

    return 0;
}
