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
    return a;
}
int main()
{
    ifstream f("date.in");
    ofstream g("date.out");
    int n,a,b;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
