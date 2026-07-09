#include <fstream>

inline constexpr int gcd(int a, int b) {
   if (b != 0) {
     return gcd(b, a % b);
   } 
   
   return a;
}

int main() {
   std::ifstream in{"euclid2.in"};
   std::ofstream out{"euclid2.out"};


   int N, a, b;
   in >> N;
   for(int i = 0; i < N; ++i) {
      in >> a >> b;
      out << gcd(a, b) << '\n';
   }

   return 0;
}
