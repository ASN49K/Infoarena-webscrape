#include <fstream>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int main()
{
  int n, s = 0, t, a;

  in >> t;

  while (t --) {
    s = 0;
    in >> n;
    for (int i = 1; i <= n; ++ i) {
      in >> a;
      s = s ^ a;
    }
    if (s)
      out << "DA\n";
    else
      out << "NU\n";
  }
  return 0;
}
