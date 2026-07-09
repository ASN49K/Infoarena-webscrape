#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,n,i;
int cmmdc(int a,int b)
{
    if(b==0)
        return a;
    else
        cmmdc(b,a%b);
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }
    return 0;
}
