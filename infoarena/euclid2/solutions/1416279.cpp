#include <iostream>
#include <fstream>
using namespace std;
int x,y,i,n;
ifstream f;
ofstream g;
int Max(int a,int b)
{
    if (a>b) return a; else return b;
}
int Min(int a,int b)
{
    if (a>b) return b; else return a;
}
int cmmdc(int a, int b)
{
    if (a==b) return a;
    else cmmdc(max(a,b)-min(a,b),min(a,b));
}
int main()
{
    f.open("euclid2.in");
    g.open("euclid2.out");
    f>>n;
    for (i=0;i<n;i++)
    {
        f>>x>>y;
        g<<cmmdc(x,y)<<"\n";
    }
}
