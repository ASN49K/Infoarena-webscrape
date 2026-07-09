#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a,int b)
{
    if(!b)
        return a;
    return cmmdc(b,a%b);
}
int main()
{
    int T,a,b;
    f>>T;
    for(int i=1;i<=T;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }
    f.close();
    g.close();
    return 0;
}
