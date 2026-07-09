#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n,a,b,d;

void euclid(int a, int b, int &d)
{
    if(b==0) {d=a;}
    else euclid(b, a%b, d);
}

int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        euclid(a,b,d);
        g<<d<<'\n';
    }

    f.close();
    g.close();
    return 0;
}
