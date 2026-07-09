#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int a,b,t,r;
    f>>t;
    while(f>>a>>b)
    {
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g<<b<<"\n";
    }
    f.close();
    g.close();
    return 0;
}
