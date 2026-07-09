#include <iostream>
#include <fstream>

using namespace std;

int n,x,y;

int cmmdc(int a, int b)
{
    if(a==1 || b==1)
        return 1;
    while(b)
    {
        int c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x>>y;
        g<<cmmdc(x,y)<<'\n';
    }
    g<<'\n';
    f.close();
    g.close();
    return 0;
}
