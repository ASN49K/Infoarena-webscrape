#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int main()
{
    int i,j,t,n,xorsum;
    for (f>>t;t;t--) {
        f>>n;
        xorsum=0;
        for (i=1;i<=n;i++) {
            f>>j;
            xorsum=xorsum^j;
        }
        if (xorsum)
            g<<"DA\n";
        else
            g<<"NU\n";
    }


    return 0;
}
