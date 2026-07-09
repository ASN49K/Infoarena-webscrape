#include <algorithm>
#include <fstream>
#include <vector>

template <class T>
std::vector<T> cmlsc(const std::vector<T> &A, const std::vector<T> &B) {
  std::vector<std::vector<int>> best(A.size(), std::vector<int>(B.size()));

  for (std::size_t i = 0; i < A.size(); ++i) {
    for (std::size_t j = 0; j < B.size(); ++j) {
      int same = (A[i] == B[j]);
      if (i == 0 && j == 0) {
        best[i][j] = same;
      } else if (i == 0) {
        best[i][j] = same + best[i][j - 1];
      } else if (j == 0) {
        best[i][j] = same + best[i - 1][j];
      } else {
        best[i][j] = same + std::max(best[i - 1][j], best[i][j - 1]);
      }
    }
  }

  std::vector<T> result;
  int i = A.size() - 1;
  int j = B.size() - 1;
  while (i != 0 && j != 0) {
    if (A[i] == B[j]) {
      result.push_back(A[i]);
      i--, j--;
    } else if (best[i - 1][j] > best[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }

  while (i != 0) {
    if (A[i] == B[j])
      result.push_back(A[i]);
    i--;
  }
  while (j != 0) {
    if (A[i] == B[j])
      result.push_back(A[i]);
    j--;
  }

  std::reverse(result.begin(), result.end());
  return result;
}

int main() {
  std::ifstream fin("cmlsc.in");
  std::ofstream fout("cmlsc.out");

  int n, m;
  fin >> n >> m;

  std::vector<int> A(n);
  for (int i = 0; i < n; ++i)
    fin >> A[i];

  std::vector<int> B(m);
  for (int i = 0; i < m; ++i)
    fin >> B[i];

  std::vector<int> res = cmlsc<int>(A, B);
  fout << res.size() << "\n";
  for (auto x : res) {
    fout << x << " ";
  }

  return 0;
}
