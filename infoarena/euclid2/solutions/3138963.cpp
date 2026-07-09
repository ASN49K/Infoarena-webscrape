#include <fstream>

#ifdef _MSC_VER
#define ALWAYS_INLINE __forceinline
#elif defined(__GNUC__)
#define ALWAYS_INLINE inline __attribute__((__always_inline__))
#else
#define ALWAYS_INLINE inline
#endif

ALWAYS_INLINE constexpr int gcd(const int& a, const int& b) {
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
