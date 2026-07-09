#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b)
{
while(a && b)
 {
    if(a>b)
    a%=b;
    else
    b%=a;
    }
    if(a)
        return a;
    return b;
}
int main()
{
int i,n,a,b;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
