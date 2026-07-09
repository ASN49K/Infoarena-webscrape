#include <bits/stdc++.h>

int main() {
#ifndef LOCAL
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);
#endif
  int M;
  int N;
  std::cin >> M >> N;
  std::vector<int> A(M + 1);
  for (int m = 1; m <= M; ++m) {
    std::cin >> A[m];
  }
  std::vector<int> B(N + 1);
  for (int n = 1; n <= N; ++n) {
    std::cin >> B[n];
  }
  std::vector<std::vector<int>> C(M + 1, std::vector<int>(N + 1, 0));
  for (int m = 1; m <= M; ++m) {
    for (int n = 1; n <= N; ++n) {
      C[m][n] = std::max(C[m - 1][n], C[m][n - 1]);
      if (A[m] == B[n]) {
        C[m][n] = std::max(C[m][n], C[m - 1][n - 1] + 1);
      }
    }
  }
  std::cout << C[M][N] << "\n";
  int m = M;
  int n = N;
  std::vector<int> arr;
  for (; m > 0 && n > 0;) {
    if (A[m] == B[n]) {
      arr.push_back(A[m]);
      --m;
      --n;
    } else {
      if (C[m - 1][n] >= C[m][n - 1]) {
        --m;
      } else {
        --n;
      }
    }
  }
  std::reverse(arr.begin(), arr.end());
  for (int i = 0; i < arr.size(); ++i) {
    if (i > 0) {
      std::cout << " ";
    }
    std::cout << arr[i];
  }
  return 0;
}