#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b;
int dd(int x,int y)
{
    while(x!=y)
    {
        if(x>y)
            x=x-y;
        else
            y=y-x;
    }
    return x;

}
int main()
{
    f>>t;
    for(int i=1; i<=t; i++)
        {f>>a>>b;
        g<<dd(a,b)<<'\n';}
    return 0;
}
