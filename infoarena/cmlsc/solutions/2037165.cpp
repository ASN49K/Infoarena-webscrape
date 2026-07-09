#include <algorithm>
#include <fstream>
#include <vector>

template <class T>
std::vector<T> cmlsc(const std::vector<T> &A, const std::vector<T> &B) {
  std::vector<std::vector<int>> best(A.size() + 1, std::vector<int>(B.size() + 1));

  for (std::size_t i = 1; i <= A.size(); ++i) {
    for (std::size_t j = 1; j <= B.size(); ++j) {
      int same = (A[i - 1] == B[j - 1]);
      best[i][j] = same + std::max(best[i - 1][j], best[i][j - 1]);
    }
  }

  std::vector<T> result;
  int i = A.size();
  int j = B.size();
  while (i != 0 && j != 0) {
    if (A[i - 1] == B[j - 1]) {
      result.push_back(A[i - 1]);
      i--, j--;
    } else if (best[i - 1][j] > best[i][j - 1]) {
      i--;
    } else {
      j--;
    }
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
