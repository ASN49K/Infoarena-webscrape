#include <iostream>
#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int gcd(int,int);

int main() {
    int A,B,T;
    in>>T;
    while (T--) {
        in>>A>>B;
        out<<gcd(max(A,B),min(A,B))<<'\n';
    }

    in.close();out.close();
    return 0;
}

int gcd(int a,int b) {
    return (b == 0) ? a : gcd(b,a%b);
}
