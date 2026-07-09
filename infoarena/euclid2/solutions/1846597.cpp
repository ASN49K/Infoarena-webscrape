#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n;

int euclid(int x, int y)
{
    int aux;
    while(y)
    {
        aux = y;
        y = x%y;
        x = aux;
    }
    return x;
}

int main()
{
    int x,y;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x>>y;
        g<<euclid(x,y)<<"\n";
    }
    return 0;
}
