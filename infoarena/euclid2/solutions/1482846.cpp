#include <fstream>
int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, const char * argv[]) {
    using namespace std;
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int t; cin >> t;
    int a;
    int b;
    while (t--){
        cin >> a;
        cin >> b;
        if (b > a) swap(a, b);
        cout << gcd(a, b) << endl;
    }
    cin.close();
    cout.close();
    return 0;
}
