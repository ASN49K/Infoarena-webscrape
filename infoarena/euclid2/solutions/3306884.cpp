#include <fstream>

unsigned long long euclid ( unsigned long long int a, unsigned long long int b) {
  if (!b) return a;
  return euclid (b, a % b);
}

int main() {

  std::fstream in("euclid2.in", std::ios::in);
  std::fstream out("euclid2.out", std::ios::out);

  std::ios_base::sync_with_stdio(false);
  in.tie(0);
  out.tie(0);

  int n;
  in >> n;
  for (int i = 1; i <= n; i++) {
    unsigned long long int x, y;
    in >> x >> y;

    out << euclid(x, y) << std::endl;
  }

  in.close();
  out.close();
  return 0;
}
