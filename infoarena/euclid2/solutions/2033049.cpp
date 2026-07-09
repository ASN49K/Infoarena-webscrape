#include <fstream>
#include <algorithm>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int n, x, y=0, z=0;
    f>>n;
    for(int i=0; i<n*2; i++)
    {
        f>>x;
        if(y==0)
            y=x;
        else
            if(z==0)
                z=x;
        if(y!=0 && z!=0)
        {
            g<<__gcd(y,z)<<'\n';
            y=0;
            z=0;
        }
    }
    return 0;
}
