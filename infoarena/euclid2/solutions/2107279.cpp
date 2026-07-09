#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g ("euclid2.out");

int gcd(int m, int n)
{
    if (n==0) return m;
    return gcd(n,m%n);
}
int main()
{
    int n,i,x,y;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x>>y;cout<<x;
        g<<gcd(x,y)<<endl;
    }

    return 0;
}
