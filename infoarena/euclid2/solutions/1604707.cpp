#include <iostream>
#include <fstream>

using namespace std;

int gcd(const int a,const int b){
    return (b==0) ? a : gcd(b, a % b);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int T;
    f>>T;
    for(int a,b;T > 0;T--){
        f >> a >> b;
        g<<gcd(a,b)<<endl;
    }
    return 0;
}
