#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int n,a,b,i;
int cmmdc(int x, int y)
{
    int aux;
    while(x!=0)
    {
        aux=y%x;
        y=x;
        x=aux;
    }
    return y;
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
