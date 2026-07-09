#include <algorithm>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int i,n,a,b;
    f >> n;
    for(i=1;i<=n;i++)
    {
        f >> a >> b;
        g << __gcd(a,b) << '\n';
    }
    return 0;

}

