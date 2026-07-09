#include <iostream>
#include <fstream>
int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}
int main()
{

    int t,a,b;
    ifstream f("euclid2.in");
    f>>t;
    ostream g("euclid2.out");
    for(t;t;t--){
        f>>a>>b;
        g<<gcd(a,b)<<"\n";
    }
    return 0;
    }

