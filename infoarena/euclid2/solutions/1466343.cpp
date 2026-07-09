#include <iostream>
#include <fstream>
using namespace std;
int euclid(int a, int b)
{
    while(a!=0)
    {
        if (a<b) swap(a, b);
        a = a%b;
    }
    return b;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int T, a, b;
    f>>T;
    while(T--)
    {
        f>>a>>b;
        g<<euclid(a,b)<<'\n';
    }
}
