#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int t,n,s,a;
int main()
{
    f>>t;
    while(t--)
    {
        f>>n;
        s=0;
        while(n--) f>>a,s^=a;
        g<<(s ? "DA":"NU")<<'\n';
    }
    return 0;
}
