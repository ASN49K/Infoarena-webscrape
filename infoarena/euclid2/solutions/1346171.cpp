#include <fstream>
#include <iostream>
using namespace std;
int euclid(int a,int b)
{
    if (!b)
    return a;
    euclid (b,a%b);
}
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int t,x,y;
    f>>t;
    while(t)
    {
        f>>x>>y;
        g<<euclid(x,y)<<endl;
        t--;
    }
}
