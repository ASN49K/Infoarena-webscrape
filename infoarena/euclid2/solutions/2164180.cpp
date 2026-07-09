#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a,int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;

    }
    return a;
    return 0;
}

int main()
{
    int n,x,y;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x>>y;
        g<<cmmdc(x,y)<<"\n";
    }
    return 0;
}
