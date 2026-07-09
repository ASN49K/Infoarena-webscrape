#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
void euclid(int a, int b)
{
    int r;
    while(b)
    {
        r = a%b
        a = b;
        b = r;
    }
    g << a;
}

int main()
{
    int n,x,y;
    f>>n;
    while(f>>x>>y)
        euclid(x,y);
    return 0;
}
