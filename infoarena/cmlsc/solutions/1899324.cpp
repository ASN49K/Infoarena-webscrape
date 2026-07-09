#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main(int argc, char const *argv[]) {

  int *subsir, *A, *B, **D, m, n, i, j, nr = 0;

  fin >> m >> n;
  int ns = max(n, m);
  A = new int[m + 1];
  B = new int[n + 1];
  D = new int *[m + 1];
  subsir = new int[ns + 1];

  for (i = 1; i <= m; i++) {
    fin >> A[i];
  }

  for (i = 1; i <= n; i++) {
    fin >> B[i];
  }

  for (i = 0; i <= m; i++) {
    D[i] = new int[n + 1];
    for (j = 0; j <= n; j++)
      D[i][j] = 0;
  }

  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) {
      if (A[i] == B[j]) {
        D[i][j] = D[i - 1][j - 1] + 1;
      } else {
        D[i][j] = max(D[i - 1][j], D[i][j - 1]);
      }
    }
  }

  for (i = m, j = n; i && j;) {
    if (A[i] == B[j]) {
      subsir[++nr] = A[i];
      --i, --j;
    } else if (D[i - 1][j] < D[i][j - 1]) {
      --j;
    } else {
      --i;
    }
  }

  fout << nr << "\n";
  for (i = nr; i >= 1; i--)
    fout << subsir[i] << " ";

  delete[] A;
  delete[] B;
  delete[] subsir;
  for (i = 1; i <= m + 1; i++) {
    delete[] D[i];
  }
  delete[] D;

  return 0;
}
