#include <fstream>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int t;

int main(){

    in >> t;
    while (t--) {
        int n, s = 0;;
        in >> n;

        for (int i = 1; i <= n; i++) {
            int x;
            in >> x;
            s ^= x;
        }
        if (s != 0)
            out << "DA" << '\n';
        else
            out << "NU" << '\n';

    }

    return 0;
}
