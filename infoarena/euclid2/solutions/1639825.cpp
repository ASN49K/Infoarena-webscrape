#include <fstream>
#include <algorithm>

using namespace std;

ifstream F ("euclid2.in");
ofstream G ("euclid2.out");

int n,a,b,r,i;
int main()
{
    F>>n;
    for ( i=1;i<=n;i++ )
    {
        F>>a>>b;
        G<<__gcd(a,b)<<'\n';
    }
    return 0;
}
