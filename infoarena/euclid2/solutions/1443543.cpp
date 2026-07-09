#include<iostream>
#include<fstream>
using namespace std;
fstream f("euclid2.in");
ofstream g("euclid2.out");
typedef unsigned int uint;

uint cmmdc(uint a,uint b)
{
    while(b)
    {
        uint r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
int n,a,b;
f>>n;
for(int i=1;i<=n;i++)
{
    f>>a>>b;
    g<<cmmdc(a,b)<<"\n";

}
return 0;
}
