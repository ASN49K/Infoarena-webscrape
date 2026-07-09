#include <fstream>

using namespace std;
int div(int a,int b)
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
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t,i,a,b;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a;
        f>>b;
        g<<div(a,b)<<'\n';
    }
    f.close();
    g.close();

    return 0;
}
