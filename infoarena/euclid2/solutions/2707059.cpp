#include <iostream>
#include <fstream>
using namespace std;
long long int a,b;
int T;
int gcd(int a, int b) {
    if (!b) return  a;
    return gcd(b, a % b);
}
int main(void) {
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in >> T;
    for(int i =1;i<=T;i++)
    {
        in >> a >> b;
        out << gcd(max(a,b),min(a,b)) << endl;

    }
    return 0;
}
