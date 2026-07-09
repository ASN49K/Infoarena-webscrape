#include <fstream>

using namespace std;

int main() {

    int i, sum, x, T, N;

    ifstream in("nim.in");
    ofstream out("nim.out");

    in >> T;

    while(T--) {

        in >> N;

        for(i = 1, sum = 0; i <= N; i++) {
            in >> x;
            sum ^= x;
            }

        out << (sum == 0 ? "NU" : "DA") << '\n';

        }

    in.close();
    out.close();

    return 0;

}
