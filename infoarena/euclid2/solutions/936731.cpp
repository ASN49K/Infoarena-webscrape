#include <fstream>
using namespace std;
ifstream ip("euclid2.in");
ofstream op("euclid2.out");
int main()
{
    long long a,b,c,r,n;
    ip>>n;
    for(c=1;c<=n;c++)
    {
        ip>>a;
        ip>>b;
        while (a%b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        op<<b<<'\n';
    }
    return 0;
}
