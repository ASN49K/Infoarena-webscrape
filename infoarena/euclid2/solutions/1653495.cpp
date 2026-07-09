#include <fstream>
using namespace std;
unsigned int div(unsigned int a,unsigned int b)
{
    while (b)
    {
        swap(a,b);
        b%=a;
    }
    return a;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    unsigned int T,i,a,b;
    f>>T;
    for (i=1;i<=T;i++)
    {
        f>>a>>b;
        g<<div(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
