#include <iostream>
#include <fstream>
using namespace std;

int gcd(int a, int b) {
    if (!b) return  a;
    return gcd(b, a % b);
}
int main(void) {
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int T;
    in >> T;
    for(int i =1;i<=T;i++)
    {
        int a,b;
        in >> a >> b;
        out << gcd(max(a,b),min(a,b)) << endl;

    }
    return 0;
}
