#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[1024], B[1024], C[1024][1024], M, N, LCS[1024], k = 0;

int max(int a, int b) { return (a > b) ? a : b; }

// Urmarim invers
void backtrack(int i, int j) {
  if (i == 0 || j == 0) {
    return;
  } else if (A[i] == B[j]) {
    LCS[k++] = A[i];
    return backtrack(i - 1, j - 1);
  } else if (C[i - 1][j] > C[i][j - 1]) {
    return backtrack(i - 1, j);
  }
  return backtrack(i, j - 1);
}

int main() {
  fin >> M >> N;
  for (int i = 1; i <= M; i++) {
    fin >> A[i];
  }

  for (int i = 1; i <= N; i++) {
    fin >> B[i];
  }

  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++) {
      if (A[i] == B[j]) {
        C[i][j] = C[i - 1][j - 1] + 1;
      } else {
        C[i][j] = max(C[i][j - 1], C[i - 1][j]);
      }
    }
  }

  // Afisam lungimea maxima a secventei
  fout << C[M][N] << '\n';

  // Gasim cea mai lunga secventa comuna
  backtrack(M, N);

  // Asifam cea mai lunaga secventa comuna
  for (int i = k - 1; i >= 0; i--) {
    fout << LCS[i] << ' ';
  }
  return 0;
}