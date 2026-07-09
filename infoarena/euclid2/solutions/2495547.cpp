#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int x,int y)
{
    int a;
    while(y!=0)
    {
        a=x%y;
        x=y;
        y=a;
    }
    return x;
}
int main()
{
    int T,x,y;
    f>>T;
    while(T)
    {
        f>>x>>y;
        g<<euclid(x,y)<<'\n';
        T--;
    }
    return 0;
}
