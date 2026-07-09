#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

#define ll long long
#define pb push_back
const int inf = 1e9 + 5;

ll euclid(ll,ll);

int main() {
    ll T,a,b;
    in>>T;
    while (T--) {
        in>>a>>b;

        out<<euclid(a,b)<<'\n';
    }

    in.close();out.close();
    return 0;
}

ll euclid(ll a,ll b) {
    if (b == 0) {
        return a;
    }

    return euclid(b,a%b);
}
