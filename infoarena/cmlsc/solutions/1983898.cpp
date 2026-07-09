#include <fstream>
#define MAX_NR_ELEMENTE 1025

using namespace std;

ifstream in ("cmlsc.in");
ofstream out("cmlsc.out");

int A[MAX_NR_ELEMENTE];
int B[MAX_NR_ELEMENTE];
int lungimeMaximaSubsir[MAX_NR_ELEMENTE][MAX_NR_ELEMENTE];
int subsir[MAX_NR_ELEMENTE];

int maxim(int numA, int numB) {
  return numA < numB ? numB : numA;
}

int main() {
  int M;
  int N;
  int lungimeSubsir;

  in >> M;
  in >> N;
  lungimeSubsir = 0;

  for (int i = 1; i <= M; i++) {
    in >> A[i];
  }

  for (int j = 1; j <= N; j++) {
    in >> B[j];
  }

  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++) {
      if (A[i] == B[j]) {
        lungimeMaximaSubsir[i][j] = 1 + lungimeMaximaSubsir[i - 1][j - 1];
        subsir[lungimeSubsir++] = A[i];
      } else {
        lungimeMaximaSubsir[i][j] = maxim(lungimeMaximaSubsir[i - 1][j],
                                        lungimeMaximaSubsir[i][j - 1]);
      }
    }
  }

  out << lungimeMaximaSubsir[M][N] << "\n";

  for (int i = 0; i < lungimeSubsir; i++) {
    out << subsir[i] << " ";
  }

  out << "\n";

  return 0;
}
