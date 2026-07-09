#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,x,y,aux;
int cmmdc(int x, int y)
{
    while(y)
    {
        aux=x;
        x=y;
        y=aux%x;
    }
    return x;
}
int main()
{
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>x>>y;
        g<<cmmdc(x,y)<<'\n';
    }
    return 0;
}
