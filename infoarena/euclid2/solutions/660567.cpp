#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b,i;

int cmmdc(int a,int b)
{
    int x=a,y=b,r;
    r=x%y;
    while(r!=0)
    {
        x=y;
        y=r;
        r=x%y;
    }
    return y;
}


int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }
    f.close();
    g.close();
    return 0;
}
