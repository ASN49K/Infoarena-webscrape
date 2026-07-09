#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int x,int y)
{
    while(x!=y)
    {
        if(x>y)
            x-=y;
        else
            y-=x;
    }
    return x;
}

int main()
{
    int n,x,y;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x>>y;
        g<<cmmdc(x,y)<<'\n';
    }
    return 0;
}
