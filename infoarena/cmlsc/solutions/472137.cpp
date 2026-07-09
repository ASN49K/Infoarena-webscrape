#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"
#define MAX_N 1024

int best[MAX_N][MAX_N], solution[MAX_N][MAX_N];

template <class type>
void longest_common_sequence(const vector<type> &a,
                             const vector<type> &b,
                             vector<type> &result) {
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < b.size(); ++j) {
      if (a[i] == b[j]) {
        best[i][j] = 1 + ((i && j) ? best[i - 1][j - 1] : 0);
        solution[i][j] = 1;
      } else {
        best[i][j] = max((i ? best[i - 1][j] : 0), (j ? best[i][j - 1] : 0));
        solution[i][j] = 0;
      }
    }
  }

  for (int i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; ) {
    if (solution[i][j]) {
      result.push_back(a[i]);
      --i;
      --j;
     } else if (i && best[i - 1][j] == best[i][j]) {
       --i;
     } else if (j && best[i][j - 1] == best[i][j]) {
       --j;
     } else {
       break;
     }
  }

  reverse(result.begin(), result.end());
}

int main(void) {
  int num_elements[2];
  vector<int> elements[2];

  freopen(FIN, "r", stdin);
  freopen(FOUT, "w", stdout);

  scanf("%d%d", num_elements, num_elements + 1);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < num_elements[i]; ++j) {
      int element;
      scanf("%d", &element);
      elements[i].push_back(element);
    }
  }

  vector<int>lcs;
  longest_common_sequence(elements[0], elements[1], lcs);

  printf("%d\n", lcs.size());
  for (vector<int>::iterator it = lcs.begin(); it != lcs.end(); ++it) {
    printf("%d ", *it);
  }
  
  return 0;
}
