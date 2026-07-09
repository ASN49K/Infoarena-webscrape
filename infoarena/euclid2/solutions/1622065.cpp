#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
void euclid(int a, int b)
{
    while(a && b)
        if(a > b)
            a -= b;
        else
            b -= a;
    if(b)
        g << b << '\n';
    else
        g << a << '\n';
}

int main()
{
    int n,x,y;
    f>>n;
    while(f>>x>>y)
        euclid(x,y);
    return 0;
}
