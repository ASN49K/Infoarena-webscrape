#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n, x, y;;

int main()
{
    f>>n;
    for(int i=0; i<n; i++)
    {
        f>>x>>y;
        if(y>x)
        {
            int a=x;
            x=y;
            y=a;
        }
        while(y!=0)
        {
            int a=x%y;
            x=y;
            y=a;
        }
        g<<x<<'\n';
    }
    return 0;
}
