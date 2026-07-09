#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int gcd(int a,int b) {
    if(!b)
        return a;
    return gcd(b,a%b);
}
int main() {
    int t,a,b;
    cin >> t;
    for(int i=0;i<t;i++) {
        cin >> a >> b;
        cout << gcd(a,b) << '\n';
    }
    return 0;
}