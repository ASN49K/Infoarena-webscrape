#include <cstring>
#include <fstream>
#include <vector>

std::vector<int> A, B, C;

void read() {
  std::ifstream fin("cmlsc.in");
  int M, N;
  fin >> M >> N;
  A.resize(M);
  B.resize(N);
  C.resize(N);
  for (auto& x : A) {
    fin >> x;
  }
  for (auto& x : B) {
    fin >> x;
  }
}

namespace {

template<class InputIter1, class InputIter2, class OutputIter>
void computeLcs(
    InputIter1 begin1, InputIter1 end1, InputIter2 begin2, InputIter2 end2, OutputIter& out,
    std::vector<int> best[2], std::vector<int> from[2]
) {
  int size1 = std::distance(begin1, end1);
  int size2 = std::distance(begin2, end2);

  if (size1 == 1) {
    for (auto it = begin2; it != end2; ++it) {
      if (*begin1 == *it) {
        *(out++) = *begin1;
        return;
      }
    }
    return;
  }

  for (int i = 0; i <= size2; ++i) {
    best[0][i] = 0;
    from[0][i] = i;
  }
  best[1][0] = 0;
  from[1][0] = 0;

  auto mid1 = begin1;
  std::advance(mid1, size1 / 2);
  bool secondHalf = false;

  for (auto it1 = begin1; it1 != end1; ++it1) {
    if (it1 == mid1) {
      secondHalf = true;
    }
    int i = 1;
    for (auto it2 = begin2; it2 != end2; ++it2, ++i) {
      auto upd = [&](int ln, int col, int v) {
        best[1][i] = best[ln][col] + v;
        if (secondHalf) {
          from[1][i] = from[ln][col];
        }
      };

      if (*it1 == *it2) {
        upd(0, i - 1, 1);
      } else if (best[0][i] < best[1][i - 1]) {
        upd(1, i - 1, 0);
      } else {
        upd(0, i, 0);
      }
    }

    std::memcpy(best[0].data(), best[1].data(), (size2 + 1) * sizeof(int));
    if (secondHalf) {
      std::memcpy(from[0].data(), from[1].data(), (size2 + 1) * sizeof(int));
    }
  }

  auto mid2 = begin2;
  std::advance(mid2, from[0][size2]);

  computeLcs(begin1, mid1, begin2, mid2, out, best, from);
  computeLcs(mid1, end1, mid2, end2, out, best, from);
}

}

template<class InputIter1, class InputIter2, class OutputIter>
OutputIter longestCommonSubsequence(
    InputIter1 begin1, InputIter1 end1, InputIter2 begin2, InputIter2 end2, OutputIter out
) {
  auto arrSize = static_cast<std::size_t>(std::distance(begin2, end2) + 1);
  std::vector<int> best[2], from[2];
  for (int i : {0, 1}) {
    best[i].resize(arrSize);
    from[i].resize(arrSize);
  }
  computeLcs(begin1, end1, begin2, end2, out, best, from);
  return out;
}

void print() {
  std::ofstream fout("cmlsc.out");
  fout << C.size() << "\n";
  for (auto x : C) {
    fout << x << " ";
  }
  fout << "\n";
}

int main() {
  read();
  C.resize(longestCommonSubsequence(A.begin(), A.end(), B.begin(), B.end(), C.begin()) - C.begin());
  print();
  return 0;
}
