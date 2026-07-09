#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

#define pb push_back
typedef long long ll;
const int NMax = 1e3 + 5;
const int inf = 1e9 + 5;

int gcd(int,int);

int main() {
    int T,a,b;
    in>>T;
    while (T--) {
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
