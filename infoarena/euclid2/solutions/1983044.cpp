#include <iostream>
#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

#define ll long long
#define pb push_back
const int NMax = 1e1 + 5;

int T;

ll euclid(ll a,ll b) {
    if (b == 0) {
        return a;
    }

    return euclid(b,a%b);
}

int main() {
    in>>T;
    while (T--) {
        ll a,b;
        in>>a>>b;
        out<<euclid(a,b)<<'\n';
    }

    in.close();out.close();
    return 0;
}
