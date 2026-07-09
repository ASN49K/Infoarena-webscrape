#include <fstream>

using namespace std;

int main () {

    int t, n, x, res;
    ifstream in ("nim.in", ifstream::in);
    ofstream out ("nim.out", ofstream::out);
    in >> t;
    while (t--)
    {
        in >> n;
        in >> res;
        n--;
        while (n--)
        {
            in >> x;
            res ^= x;
        }
        if (res == 0)
            out << "NU\n";
        else
            out << "DA\n";
    }
}
