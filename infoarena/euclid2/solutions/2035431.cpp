#include <fstream>
#define var auto

int main()
{
  std::ifstream in("euclid2.in");
  std::ofstream out("euclid2.out");

  int t;
  in >> t;

  for (t; t; --t)
  {
    int a, b;
    in >> a >> b;

    int c;
    while (b)
    {
      c = a % b;
      a = b;
      b = c;
    }

    out << a << '\n';
  }
}
