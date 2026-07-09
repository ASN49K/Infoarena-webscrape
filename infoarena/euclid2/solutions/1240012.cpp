#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int a, b, n, gcd;
    in>>n;
    for(int i=1; i<=n; ++i){
        in>>a>>b;
        gcd = __gcd(a,b);
        out<<gcd;
    }

    return 0;
}
