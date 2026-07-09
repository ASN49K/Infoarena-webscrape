#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    long a,b,r,n,i;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++)
    {
    f>>a>>b;
    while(a%b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }

    g<<b<<'\n';

  }


    f.close();
    g.close();
    return 0;
}
