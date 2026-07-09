#include <fstream>

using namespace std;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b,a%b);
}

int t,a,b;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int main()
{
    cin>>t;
    while (t--) {
        cin>>a>>b;
        cout<<gcd(a,b)<<'\n';
    }
    return 0;
}
