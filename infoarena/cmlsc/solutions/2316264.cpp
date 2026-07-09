#include <fstream>
#include <vector>
using namespace std;

int main() {
  ifstream f("cmlsc.in");
  ofstream v("cmlsc.out");
  int n, m;
  f >> n >> m;
  vector<vector<int>> matrice(n + 1, vector<int>(m + 1));
  vector<int> sir1(n + 1), sir2(m + 1);
  for (auto i = 1; i < n + 1; i++)
    f >> sir1[i];
  for (auto i = 1; i < m + 1; i++)
    f >> sir2[i];
  for (auto x = 1; x < n + 1; x++) {
    for (auto y = 1; y < m + 1; y++) {
      matrice[x][y] = max(matrice[x - 1][y], matrice[x][y - 1]);
      if (sir1[x] == sir2[y])
        matrice[x][y] = max(matrice[x - 1][y], matrice[x][y - 1]) + 1;
    }
  }
  int i = 1;
  vector<int> raspuns;
  for (auto x = 1; x < n + 1; x++)
    for (auto y = 1; y < m + 1; y++) {
      if (matrice[x][y] >= i) {
        raspuns.push_back(sir1[x]);
        i++;
      }
    }
  v << raspuns.size() << endl;
  for (auto x : raspuns)
    v << x << " ";
}
