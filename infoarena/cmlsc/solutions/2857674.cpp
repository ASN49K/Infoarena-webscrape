#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

int cmlscLungime(std::vector<int> A, std::vector<int> B) {
  int m = A.size();
  int n = B.size();

  std::vector<std::vector<int>> C(m + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (A[i - 1] == B[j - 1]) {
        C[i][j] = C[i - 1][j - 1] + 1;
      } else {
        C[i][j] = std::max(C[i][j - 1], C[i - 1][j]);
      }
    }
  }
  return C[m][n];
}
std::vector<int> __cmlsc(std::vector<int> A, std::vector<int> B, int x, int y) {
  int m = x;
  int n = y;

  std::vector<std::vector<int>> C(m + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (A[i - 1] == B[j - 1]) {
        C[i][j] = C[i - 1][j - 1] + 1;
      } else {
        C[i][j] = std::max(C[i][j - 1], C[i - 1][j]);
      }
    }
  }

  int index = C[m][n];
  std::vector<int> lcs(index);

  int k = m;
  int l = n;
  while (k > 0 && l > 0) {
    if (A[k - 1] == B[l - 1]){
      lcs[index - 1] = A[k - 1];
      k--; l--; index--;
    }
    else if (C[k - 1][l] > C[k][l - 1]) {
      k--;
    }
    else {
      l--;
    }
  }

  return lcs;
}
std::vector<int> cmlsc(std::vector<int> A, std::vector<int> B) {
  return __cmlsc(A, B, A.size(), B.size());
}

int main() {
  std::fstream in;
  in.open("cmlsc.in", std::ios::in);

  int M, N;
  if (!in.is_open()) {
    std::cerr << "File could not be opened." << std::endl;
    exit(EXIT_FAILURE);
  }

  std::vector<int> A;
  int el;
  while (in >> el && M) {
    A.push_back(el);
    M--;
  }

  std::vector<int> B;
  while (in >> el && N) {
    B.push_back(el);
    N--;
  }

  in.close();
  std::fstream out;
  out.open("cmlsc.out", std::ios::out);

  out << cmlscLungime(A, B) << std::endl; // cmlsc.size()
  std::vector<int> cmlsc = cmlsc(A, B);
  std::copy(cmlsc.begin(), cmlsc.end(), std::ostream_iterator<int>(out, " "));

  out.close();
  exit(EXIT_SUCCESS);
}
