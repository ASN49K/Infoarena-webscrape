#include <iostream>
#include <fstream>

#define LIM 1024

using namespace std;

ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
int mls[LIM+1][LIM+1], na, nb, nc, ia, ib, ic, a[LIM+1], b[LIM+1], c[LIM+1];

void matrice () {
  int ia, ib;

  for (ia = 1; ia <= na; ia++) {
    for (ib = 1; ib <= nb; ib++)
      cout << mls[ia][ib] << ' ';
    cout << endl;
  }
}

int main () {
  fi >> na >> nb;
  for (ia = 1; ia <= na; ia++)
    fi >> a[ia];
  for (ib = 1; ib <= nb; ib++)
    fi >> b[ib];
  for (ia = 1; ia <= na; ia++)
    for (ib = 1; ib <= nb; ib++)
      if (a[ia] == b[ib])
        mls[ia][ib] = 1 + mls[ia-1][ib-1];
      else
        if (mls[ia-1][ib] > mls[ia][ib-1])
          mls[ia][ib] = mls[ia-1][ib];
        else
          mls[ia][ib] = mls[ia][ib-1];
  //matrice();
  ic = nc = mls[na][nb]; ia = na; ib = nb;
  do {
    if (a[ia] == b[ib]) {
      c[ic--] = a[ia];
      ia--; ib--;
    }
    else
      if (mls[ia][ib] == mls[ia-1][ib])
        ia--;
      else
        ib--;
  } while ((ia >= 1) and (ib >= 1));
  fo << nc << '\n';
  for (ic = 1; ic <= nc; ic++)
    fo << c[ic] << ' ';
  return 0;
}
