#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid ( int a, int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int n,x,y,i;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x>>y;
        g<<euclid(x,y)<<'\n';
    }
    return 0;
}
