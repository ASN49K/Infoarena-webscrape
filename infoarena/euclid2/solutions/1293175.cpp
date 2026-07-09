#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a,int b)
{
    if(a!=b)
    {
        if(a>b)
            cmmdc(a-b,b);
        else
            cmmdc(b,b-a);
    }
    else
        return a;
}

int main()
{
    int t,a,b;
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }
    f.close();
    g.close();
    return 0;
}
