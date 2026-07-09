#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a, int b)
{
    if(b==0) return a;
    else return euclid(b, a%b);
}

int main()
{
    int i, n, a, b;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        int div=euclid(a,b);
        g<<div<<'\n';
    }
    return 0;
}
