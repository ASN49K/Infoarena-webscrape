#include <fstream>

using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, xorp = 0;
        cin >> n;
        while(n--) {
            int a;
            cin >> a;
            xorp ^= a;
        }
        if(xorp)
            cout << "DA\n";
        else
            cout << "NU\n";
    }
    return 0;
}