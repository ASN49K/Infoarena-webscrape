#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,t;
int cmmdc(int x,int y)
{
    int R;
    while(y)
    {
        R=x%y;
        x=y;
        y=R;
    }
    return x;
}
int main()
{
    f>>t;
    while(t)
    {
        f>>a>>b;
        g<<cmmdc(a,b);
        g<<'\n';
        t--;
    }
}
