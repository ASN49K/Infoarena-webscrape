#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,n,i;
void cmmdc(int a, int b)
{
    int t;
    while(b!=0)
    {

        t=b;
        b=a%b;
        a=t;
    }
    g<<a<<"\n";
}
int main()
{
    f>>n;
    for(i=1; i<=n; ++i)
    {
        f>>a>>b;
        cmmdc(a,b);
    }




}
