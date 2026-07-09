#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int x,int y)
{
    while (x!=y)
    {
        if (x>y)
            x=x-y;
        else
            y=y-x;
    }
    return x;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    long t,i;
    int x,y;
    f>>t;
    for (i=0;i<t;i++)
    {
        f>>x;
        f>>y;
        g<<cmmdc(x,y)<<"\n";
    }
    f.close();
    g.close();
    return 0;
}
