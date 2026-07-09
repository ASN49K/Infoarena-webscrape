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

        int min_value = min(a,b);

        for(int d = min_value; d>=1; d--) {
            if(a % d == 0 && b % d == 0) {
               res = d;
               break;
            }
        }

        out << res << endl;

        t--;
    }

    return 0;
}
