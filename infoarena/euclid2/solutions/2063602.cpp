#include <iostream>
#include <fstream>>

using namespace std;

int main () {
    ifstream in ("euclid2.in");
    ofstream out ("euclid2.out");

    int a;
    int b;
    int res;
    int t;

    cin >> t;

    while (t > 0) {
        cin >> a >> b;

        while ( b != 0) {
            res = b;
            b = a % b;
            a = res;
        }
        cout << res << endl;

        t--;
    }



    return 0;
}
