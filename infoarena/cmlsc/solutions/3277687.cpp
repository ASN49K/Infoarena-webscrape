// https://infoarena.ro/problema/cmlsc

#include <fstream>

#define LIM 1024

using namespace std;

ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
int mls[LIM + 1][LIM + 1], na, nb, nc, ia, ib, ic, a[LIM + 1], b[LIM + 1], c[LIM + 1];

int main() {
    fi >> na >> nb;
    for (ia = 1; ia <= na; ia++)
        fi >> a[ia];
    for (ib = 1; ib <= nb; ib++)
        fi >> b[ib];
    for (ia = 1; ia <= na; ia++)
        for (ib = 1; ib <= nb; ib++)
            if (a[ia] == b[ib])
                mls[ia][ib] = 1 + mls[ia][ib - 1]; // Lungimea subsirului creste.
            else                                       //
                if (mls[ia - 1][ib] > mls[ia][ib - 1]) // Alegem valoarea mai mare.
                    mls[ia][ib] = mls[ia - 1][ib];
                else
                    mls[ia][ib] = mls[ia][ib - 1];
    ic = nc = mls[na][nb];
    ia = na;
    ib = nb; // Ne deplasam pornind din colt
    do {
        if (a[ia] == b[ib]) { // Elementele din a si b sunt egale.
            c[ic--] = a[ia];  // Retinem elementul comun.
            ia--;
            ib--; // Ne deplasam pe diagonala.
        }
        else //
            if (mls[ia][ib] == mls[ia - 1][ib])
                ia--; // deplasare in sus
            else
                ib--;                  // deplasare in staga
    } while ((ia >= 1) and (ib >= 1)); // pana iesim din matrice
    fo << nc << '\n';
    for (ic = 1; ic <= nc; ic++)
        fo << c[ic] << ' ';
    return 0;
}
