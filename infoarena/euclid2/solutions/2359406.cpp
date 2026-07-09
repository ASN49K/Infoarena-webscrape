#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int T,x,y,r;
    f>>T;
    for(int i=1;i<=T;i++)
    {
        f>>x>>y;
        while(y!=0)
        {
            r=x%y;
            x=y;
            y=r;
        }
        g<<x<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
