#include <fstream>
using namespace std;
ifstream f("euclid2.in"); ofstream g("euclid2.out");
int n,a,b;
int cmmdc(int x, int y)
{
    int r;
    while(y)
        {r=x%y;
        x=y;
        y=r;
        }
    return x;
}
int main()
{
    f>>n;
    while(n--){f>>a>>b;cmmdc(a,b);}
    g.close();
    return 0;
}
