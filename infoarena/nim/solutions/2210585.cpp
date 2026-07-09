#include <fstream>
#include <vector>

using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");

int main() {
    int t;
    cin >> t;
    for(int qr = 1; qr <= t; qr ++) {
        int n, s = 0;
        cin >> n;
        for(int i = 1; i <= n; i ++) {
            int x;
            cin >> x;
            s ^= x;
        }
        if(s > 0)
            cout << "DA\n";
        else
            cout << "NU\n";
    }

    return 0;
}
