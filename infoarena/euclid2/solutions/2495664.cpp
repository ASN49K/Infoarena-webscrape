#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int CMMDC(int a, int b)
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
    int T, a, b;
    f>>T;
    for(int i=1; i<=T; i++)
    {
        f>>a>>b;
        g<<CMMDC(a, b)<<endl;
    }
    return 0;
}
