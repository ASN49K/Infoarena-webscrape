#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>

std::vector<int> solve(const std::vector<int> &a, const std::vector<int> &b) {
  int n = a.size(), m = b.size();
  std::vector<std::vector<int>> D(n + 1, std::vector<int>(m + 1, 0));

  // forward DP
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] == b[j - 1]) {
        D[i][j] = D[i - 1][j - 1] + 1;
      } else {
        D[i][j] = std::max(D[i - 1][j], D[i][j - 1]);
      }
    }
  }

  std::vector<int> cmlscRev;
  int i = n, j = m;

  // backwards DP to reconstruct solution
  while (i && j) {
    if (a[i - 1] == b[j - 1]) {
      cmlscRev.push_back(a[i - 1]);
      i--, j--;
    } else if (D[i - 1][j] >= D[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }

  return std::vector<int>(cmlscRev.rbegin(), cmlscRev.rend());
}

void read(std::vector<int> &, std::vector<int> &);
void write(const std::vector<int> &);

int main() {
  std::vector<int> a, b;

  read(a, b);
  auto cmlsc = solve(a, b);
  write(cmlsc);

  return 0;
}

void read(std::vector<int> &a, std::vector<int> &b) {
  std::ifstream fin("cmlsc.in");
  int n, m;

  fin >> n >> m;
  std::copy_n(std::istream_iterator<int>(fin), n, std::back_inserter(a));
  std::copy_n(std::istream_iterator<int>(fin), m, std::back_inserter(b));
}

void write(const std::vector<int> &v) {
  std::ofstream fout("cmlsc.out");

  fout << v.size() << '\n';
  std::copy_n(v.begin(), v.size(), std::ostream_iterator<int>(fout, " "));
  fout << '\n';
}