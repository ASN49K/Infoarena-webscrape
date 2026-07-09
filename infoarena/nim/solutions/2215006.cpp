#include <fstream>

using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");

int main()
{
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        int val, xur(0);
        for (int j = 0; j < n; ++j) {
            cin >> val;
            xur ^= val;
        }
        if (xur) {
            cout << "DA\n";
        }
        else {
            cout << "NU\n";
        }
    }
    return 0;
}
