#include <iostream>
#include <fstream>
int cmmdc(int a,int b)
{
int r;
while(b!=0)
{
    r=a%b;
    a=b;
    b=r;
}
return a;
}

using namespace std;

int main()
{
    int t,a,b,i;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<"\n";
    }
    f.close();
    g.close();
    return 0;
}
