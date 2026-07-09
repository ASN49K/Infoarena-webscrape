# include <iostream>
# include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int a,b,n,r;

void euclid()
{
    while(a%b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    g<<b<<'\n';
}

int main()
{
    f>>n;
    for(int i=1; i<=n; i++)
    {
        f>>a>>b;
        euclid();
    }
    return 0;
}
