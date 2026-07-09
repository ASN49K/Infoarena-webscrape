#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

const int NMax = 1e5 + 50;

int T;

int gcd(int,int);

int main() {
    in>>T;
    while (T--) {
        int a,b;
        in>>a>>b;
        out<<gcd(a,b)<<'\n';
    }

    in.close();out.close();
    return 0;
}

int gcd(int a,int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b,a%b);
}
