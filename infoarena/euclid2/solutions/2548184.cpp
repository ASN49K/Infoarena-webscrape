#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int x,int y)
{
    if(!y)
        return x;
    return cmmdc(y,x%y);
}

int main()
{
    int n,x,y;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(;n;n--)
    {
        f>>x>>y;
        g<<cmmdc(x,y)<<'\n';
    }
    return 0;
}
