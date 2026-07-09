#include <bits/stdc++.h>

using namespace std;

FILE *fin = fopen ("nim.in", "r"), *fout = fopen ("nim.out", "w");

int main() {
  int t, n, s, i, a;
  fscanf (fin, "%d", &t);
  while (t--) {
    fscanf (fin, "%d", &n);
    s = 0;
    for (i = 1; i <= n; i++) {
      fscanf (fin, "%d", &a);
      s ^= a;
    }
    fprintf (fout, "%s\n", (s == 0) ? "NU" : "DA");
  }
  fclose (fin);
  fclose (fout);
  return 0;
}
