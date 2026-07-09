#include <fstream>

using namespace std;
int cmmdc( int a, int b)
{
    int c;
    while (b!=0)
    {
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}
int t;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for (int i=1; i<=t; i++)
    {
        int a, b;
        f>>a>>b;
        g<<cmmdc(a, b)<<'\n';
    }
    return 0;
}
