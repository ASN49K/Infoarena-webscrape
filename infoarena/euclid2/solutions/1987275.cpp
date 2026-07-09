#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n,x,y,i;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for (i=1;i<=n;i++)
    {
        f>>x>>y;
        while(x!=y)
        {
            if (x>y) x=x-y;
            else y=y-x;
        }
        if (y!=1) g<<y<<"\n";
    }
    return 0;
}
