#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("euclid2.in"); ofstream g("euclid2.out");
    int i,n,x,y,r;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x>>y;
        do
        {
            r=x%y;
            x=y;
            y=r;
        }
        while (r>0);
        g<<x<<'\n';
    }
    return 0;
}
