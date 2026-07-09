#include <fstream>

int gcd(int x, int y) {
   return y ? gcd(y, x % y) : x;
}

int main() {
   std::ifstream in {"euclid2.in"};
   std::ofstream out {"euclid2.out"};

   int T, x, y;

   for (in >> T; T; --T ) {
      in >> x >> y;
      out << gcd(x, y) << '\n';
   }

   return 0;
}
