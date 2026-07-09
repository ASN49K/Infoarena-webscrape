#include <fstream>

using namespace std;

int l1, l2, s1[1025], s2[1025], d[1025][1025], sol[1025], lmax;

int main () {
  ifstream fi("cmlsc.in");
  ofstream fo("cmlsc.out");
  fi >> l1 >> l2;
  for (int i = 1; i <= l1; i++)
    fi >> s1[i];
  for (int i = 1; i <= l2; i++)
    fi >> s2[i];
  for (int i = 1; i <= l1; i++)
    for (int j = 1; j <= l2; j++)
      if (s1[i] == s2[j])
        d[i][j] = d[i-1][j-1]+1;
      else
        d[i][j] = max(d[i-1][j], d[i][j-1]);
  for (int i = l1, j = l2; i;) {
    if (s1[i] == s2[j])
      sol[++lmax] = s1[i], i--, j--;
    else
      if (d[i-1][j] > d[i][j-1])
        i--;
      else
        j--;
  }
  fo << lmax << '\n';
  for (int i = lmax; i; i--)
    fo << sol[i] << ' ';
  return 0;
}
