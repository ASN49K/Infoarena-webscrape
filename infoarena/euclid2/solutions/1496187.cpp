#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t;
int x,y,z;

int main()
{
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>x>>y;
        while(x%y)
        {
            z=x;
            x=y;
            y=z%y;
        }
        g<<y<<"\n";
    }

    return 0;
}
