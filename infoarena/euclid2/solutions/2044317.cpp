#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

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
        g<<c<<"\n";
    }
    return 0;
}
