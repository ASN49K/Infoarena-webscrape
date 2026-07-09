#include <fstream>
using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");


int main() {

    int t, n, x;
    in>>t;
    while (t--) {
        int sol = 0;
        in >> n;
        for (int i = 1; i <= n; ++i){
            in >> x;
            sol ^= x;
        }
        if (sol)
            out << "DA" << '\n';
        else
            out << "NU" << '\n';
    }
    in.close();
    out.close();
    return 0;

}
