#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,a,b;
int eul (int x,int y)
{
    int r=x%y;
    while (r!=0)
    {
        x=y;
        y=r;
        r=x%y;
    }
    return y;
}
int main()
{
    f>>n;
    for (int i=0; i<n; i++)
    {
        f>>a>>b;
        g<<eul(a,b)<<'\n';
    }
    return 0;
}
