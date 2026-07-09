#include <fstream>
using namespace std;
ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

int gcd(int a,int b)
{
    if (!b) return a;
    return gcd(b,a%b);
}

int main()
{
    int t;
    fi>>t;
    for (int i=1; i<=t; i++)
    {
        int a,b;
        fi>>a>>b;
        fo<<gcd(a,b)<<"\n";
    }
    fi.close();
    fo.close();
    return 0;
}
