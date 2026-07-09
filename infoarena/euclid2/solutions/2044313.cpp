#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmmdc.in");
ofstream g("cmmdc.out");

int cmmdc(int x, int y)
{
    if(y!=0)
    {
        return cmmdc(y, x%y);
    }
    else
    {
        return x;
    }
}

int main()
{
    int n,a, b, c;
    f>>n;
    for(int i = 0; i<n; i++)
    {
        f>>a>>b;
        c = cmmdc(a, b);
        if(c == 1)
            g<<"0"<<"\n";
        else
            g<<c<<"\n";
    }
    return 0;
}
