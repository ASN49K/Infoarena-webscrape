#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a, int b)
{
    if(a == 0)return b;
    if(b == 0)return a;
    if(a > b)return euclid(a%b,b);
    return euclid(b%a,a);
}


int main()
{
    int n, i, a, b;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<euclid(a, b)<<'\n';
    }
    return 0;
}
