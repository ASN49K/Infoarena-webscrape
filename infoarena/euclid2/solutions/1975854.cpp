#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a, int b)
{
    if(!b)return a;
    else return cmmdc(b, a%b);
}
int main()
{
    int x, y, t;
    f>>t;
    while(t)
    {
        f>>x>>y;
        g<<cmmdc(x, y)<<'\n';
        t--;
    }
    f.close();
    g.close();
    return 0;
}
