#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int gcd(int a,int b){if (b==0) return a; return gcd(b,a%b);}
int main()
{
    int t,a,b; f>>t;
    while(t--){ f>>a>>b;g<<gcd(a,b)<<'\n';}
    return 0;
}
