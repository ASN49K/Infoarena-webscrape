#include <iostream>
#include<fstream>
using namespace std;
long long cmmdc(long long a, long long b)
{
    int r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    long long n,x,y;
    fstream f("euclid2.in",ios::in);
    fstream g("euclid2.out",ios::out);
    f>>n;
    while(n>0)
    {
        f>>x>>y;
        g<<cmmdc(x,y)<<"\n";
        n--;
    }
    f.close();
    g.close();
}
