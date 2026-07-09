#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int n,a,b,minx,i,j;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        if(a>b)
        {
            minx=b;
        }
        else
        {
            minx=a;
        }
        for(j=minx;j>=1;i++)
        {
            if(a%j==0&&b%j==0)
            {
                break;
            }
        }
        g<<j<<'\n';
    }
    return 0;
}
