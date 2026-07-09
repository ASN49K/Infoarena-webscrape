#include <fstream>
using namespace std;
ifstream f("euclid2.in"); ofstream g("euclid2.out");
int n,a,b;
void cmmdc(int x, int y)
{
    int r;
    while(y)
        {r=x%y;
        x=y;
        y=r;
        }
    g<<x;
}
int main()
{
    f>>n;
    while(n--){f>>a>>b;cmmdc(a,b);g<<'\n';}
    g.close();
    return 0;
}
