#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int a,b,d,n;
    f>>n;
    while(n)
    {   f>>a>>b;
        d=cmmdc(a,b);
        g<<d<<"\n";
        n--;
    }
    return 0;
}
