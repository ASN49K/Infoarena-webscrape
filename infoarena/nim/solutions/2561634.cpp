#include <fstream>

using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");

int main() {
    int t;
    cin >> t;
    for(int test = 1; test <= t; ++test) {
        int n, s = 0;
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            s ^= x;
        }
        if(s == 0)
            cout << "NU\n";
        else
            cout << "DA\n";
    }
    return 0;
}