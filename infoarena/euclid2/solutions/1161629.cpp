#include <fstream>

using namespace std;

int T, A, B;

int Euclid(int A, int B) {
    if(!B) return A;
    return Euclid(B, A % B);
}

int main() {
    ifstream in("euclid2.in"); ofstream out("euclid2.out");
    for(in >> T; T; T--) {
        in >> A >> B;
        out << Euclid(A, B) << "\n";
    } in.close(); out.close();
}
