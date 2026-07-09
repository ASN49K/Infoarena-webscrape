#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a,int b)
{
    while(b != 0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a>0 ? a:-a;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,a,b;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }
    f.close();
    g.close();
}
