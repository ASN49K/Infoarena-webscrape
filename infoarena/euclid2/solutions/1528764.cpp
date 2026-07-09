#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,nr;
int gcd (int a,int b)
{   if(!b)
     return a;
    return gcd(b,a%b);
}
int main()
{f>>nr;
    for(int i=1; i<=nr; i++)
    {
        f>>a>>b;
        g<<gcd(a,b);
        g<<'\n';
    }

    return 0;
}
