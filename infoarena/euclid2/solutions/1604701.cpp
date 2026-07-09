#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T,a,b;

int gcd(int a, int b){
    return (b==0) ? a : gcd(b, a % b);
}

int main()
{
    f>>T;
    for(;T > 0;T--){
        f>>a>>b;
        g<<gcd(a,b)<<endl;
    }
    return 0;
}
