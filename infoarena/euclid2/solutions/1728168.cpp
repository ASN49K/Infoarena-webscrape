#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int x,y,i,T,r;
    f>>T;
    for(i=1;i<=T;i++)
    {
        f>>x>>y;
        while(y!=0)
        {
           r=x%y;
           x=y;
           y=r;
        }
        g<<x<<endl;
    }
    f.close();
    g.close();
    return 0;
}
