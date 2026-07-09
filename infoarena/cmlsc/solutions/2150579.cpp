#include <fstream>
#include <vector>

using namespace std;

using Matrix = vector<vector<int>>;

inline Matrix BuildMatrix(int rows, int cols, int init_val)
{
  return Matrix(rows, vector<int>(cols, init_val));
}

vector<int> ReadVector(ifstream &fin, int size)
{
  vector<int> vec(size);
  for (auto &elem : vec) {
    fin >> elem;
  }
  return vec;
}

vector<int> ConstructLcs(const Matrix &lcs,
                         const vector<int> &a,
                         const vector<int> &b)
{
  vector<int> res(lcs.back().back());
  auto index = res.size() - 1;

  auto row = lcs.size() - 1;
  auto col = lcs[0].size() - 1;

  while (row > 0 && col > 0) {
    if (a[row - 1] == b[col - 1]) {
      res[index--] = a[row - 1];
      row -= 1;
      col -= 1;
    } else if (lcs[row - 1][col] > lcs[row][col - 1]) {
      row -= 1;
    } else {
      col -= 1;
    }
  }
  return res;
}

vector<int> FindLcs(const vector<int> &a, const vector<int> &b)
{
  auto len = BuildMatrix(a.size() + 1, b.size() + 1, 0);
  for (size_t i = 1; i <= a.size(); ++i) {
    for (size_t j = 1; j <= b.size(); ++j) {
      if (a[i - 1] == b[j - 1]) {
        len[i][j] = len[i - 1][j - 1] + 1;
      } else {
        len[i][j] = max(len[i - 1][j], len[i][j - 1]);
      }
    }
  }

  return ConstructLcs(len, a, b);
}

int main()
{
  ifstream fin("cmlsc.in");
  ofstream fout("cmlsc.out");

  int n, m;
  fin >> n >> m;

  auto vec1 = ReadVector(fin, n);
  auto vec2 = ReadVector(fin, m);

  auto lcs = FindLcs(vec1, vec2);
  fout << lcs.size() << "\n";

  for (const auto &elem : lcs) {
    fout << elem << " ";
  }
  fout << "\n";

  return 0;
}
