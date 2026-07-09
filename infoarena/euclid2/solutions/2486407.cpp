#include <fstream>
using namespace std;
int cmmdc(long a,long b)
{
    if(b==0) return a;
    else return cmmdc(b,a%b);
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n;
    long a,b;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
