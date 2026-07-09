#include <fstream>
#include <iostream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a,int b)
{
    int r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main()
{
    int t,a,b,i;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }

    return 0;
}
