#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define pb push_back
#define mp make_pair
const int NMax = 5e4 + 5;
const int inf = 1e9 + 5;
const int mod = 100003;
using zint = int;

int T;

int gcd(int a,int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b,a%b);
}

int main() {
    in>>T;
    while(T--) {
        int a,b;
        in>>a>>b;
        out<<gcd(b,a%b)<<'\n';
    }

    in.close();out.close();
    return 0;
}
