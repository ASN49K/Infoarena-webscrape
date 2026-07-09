#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int x, int y)
{
    if(y == 0)
        return x;
    return cmmdc(y,x%y);
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a, b, n, i;
    f>>n;
    for(i = 0; i < n; i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
