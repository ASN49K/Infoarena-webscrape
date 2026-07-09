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

    in >> t;

    while (t > 0) {
        in >> a >> b;

        while ( b != 0) {
            res = b;
            b = a % b;
            a = res;
        }
        out << res << endl;

        t--;
    }



    return 0;
}
