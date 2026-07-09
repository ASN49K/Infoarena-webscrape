#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int CMMDC(int a, int b)
{
    if(b>0)
        return CMMDC(b, a%b);
    else
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
