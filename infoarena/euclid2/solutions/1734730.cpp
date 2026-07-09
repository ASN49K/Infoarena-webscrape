#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a, b, n;
int euclid(int a, int b)
{
    int r;
    while(b)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    f >> n;
    for(int i=1;i<=n;i++)
    {
        f >> a >> b;
        g << euclid(a,b) << '\n';
    }
    return 0;
}
