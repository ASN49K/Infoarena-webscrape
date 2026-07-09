#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int CMMDC(int a, int b)
{
    if(b==0)
        return a;
    return CMMDC(b, a%b);
}

int main()
{
    int T, a, b, i;
    f>>T;
    for(i=1; i<=T; i++)
    {
        f>>a>>b;
        g<<CMMDC(a, b)<<endl;
    }
    return 0;
}
