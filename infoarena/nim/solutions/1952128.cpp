#include <iostream>
#include <fstream>

using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");

const int NMax = 1e5 + 5;

int T,N;

int main() {
    in>>T;
    while (T--) {
        in>>N;

        int xorSum = 0;
        for (int i=1;i<=N;++i) {
            int val;
            in>>val;
            xorSum ^= val;
        }

        // daca suma xor este 0, atunci, printr-o mutare,
        // se ajunge obligatoriu intr-o stare in care suma xor este nenula

        // daca suma xor este nenula, atunci, printr-o mutare,
        // se poate ajunge intr-o stare in care suma xor este 0
        // (daca jucatorul joaca optim, va vrea sa faca o astfel de mutare)

        // daca ambii joaca optim, primul jucator va castiga doar daca
        // porneste dintr-o stare in care suma xor este nenula
        if (xorSum != 0) {
            out<<"DA\n";
        }
        else {
            out<<"NU\n";
        }
    }
    in.close();out.close();
    return 0;
}

