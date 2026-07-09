#include <fstream>

using namespace std;
typedef long long ll;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

ll t;
ll a, b;

ll gcd() {
    ll r;
    while(b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    fin.tie(0);
    fout.tie(0);

    fin >> t;
    while(t--) {
        fin >> a >> b;
        fout << gcd() << "\n";
    }
    return 0;
}
