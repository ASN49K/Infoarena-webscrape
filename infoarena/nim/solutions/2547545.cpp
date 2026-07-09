#include<fstream>
using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int T, N;

int main() {
    in >> T;
    while(T--) {
        in >> N;
        int a = 0;
        for (int i = 0,x; i < N; i++) {
            in >> x;
            a ^= x;
        }
        if (!a)
            out << "NU" << '\n';
        else
            out << "DA" << '\n';
    }
}
