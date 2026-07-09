#include <fstream>

using namespace std;

int euclid(int a,int b)
{
    int r;
    while (b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    int a,b,n,i;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for (i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<"\n";
    }
    return 0;
}
