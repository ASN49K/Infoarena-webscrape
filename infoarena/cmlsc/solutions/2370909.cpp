#include <fstream>

const int N_MAX = 1024;

int M, N;
int A[N_MAX + 5], B[N_MAX + 5];

int best[2][N_MAX + 5];
int from[2][N_MAX + 5];
int S;
int C[N_MAX + 5];

void read() {
  std::ifstream fin("cmlsc.in");
  fin >> M >> N;
  for (int i = 1; i <= M; ++i) {
    fin >> A[i];
  }
  for (int i = 1; i <= N; ++i) {
    fin >> B[i];
  }
}

void solve(int al, int ar, int bl, int br) {
  if (al == ar) {
    for (int i = bl; i <= br; ++i) {
      if (A[al] == B[i]) {
        C[++S] = A[al];
        return;
      }
    }
    return;
  }

  for (int i = bl - 1; i <= br; ++i) {
    best[0][i] = 0;
    from[0][i] = i;
  }
  best[1][bl - 1] = 0;
  from[1][bl - 1] = 0;

  int mid = (al + ar) / 2;

  for (int i = al; i <= ar; ++i) {
    for (int j = bl; j <= br; ++j) {
      auto upd = [&](int ln, int col, int v) {
        best[1][j] = best[ln][col] + v;
        if (i > mid) {
          from[1][j] = from[ln][col];
        }
      };

      if (A[i] == B[j]) {
        upd(0, j - 1, 1);
      } else if (best[0][j] < best[1][j - 1]) {
        upd(1, j - 1, 0);
      } else {
        upd(0, j, 0);
      }
    }

    for (int j = bl; j <= br; ++j) {
      best[0][j] = best[1][j];
      if (i > mid) {
        from[0][j] = from[1][j];
      }
    }
  }

  int bmid = from[0][br];
  solve(al, mid, bl, bmid);
  solve(mid + 1, ar, bmid + 1, br);
}

void print() {
  std::ofstream fout("cmlsc.out");
  fout << S << "\n";
  for (int i = 1; i <= S; ++i) {
    fout << C[i] << " ";
  }
  fout << "\n";
}

int main() {
  read();
  solve(1, M, 1, N);
  print();
  return 0;
}
