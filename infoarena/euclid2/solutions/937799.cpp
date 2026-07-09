#include <fstream>
using namespace std;
int euclid2(int a,int b)
{
    int t;
    while(b)
    {
        t=b;
        b=a%t;
        a=t;
    }
    return a;
}
int main()
{   int a,b,i,t;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<euclid2(a,b)<<'\n';

    }
    f.close(); g.close();
    return 0;
}
