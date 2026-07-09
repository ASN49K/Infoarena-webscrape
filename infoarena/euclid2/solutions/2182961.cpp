#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define mp make_pair
#define CHECK(x) if(!(x)) return false;
typedef pair<int, int> pii;

#ifdef INFOARENA
#define ProblemName "euclid2"
#endif

#define MCONCAT(A, B) A B
#ifdef ProblemName
#define InFile MCONCAT(ProblemName, ".in")
#define OuFile MCONCAT(ProblemName, ".out")
#else
#define InFile "fis.in"
#define OuFile "fis.out"
#endif

int main() {
  freopen(InFile, "r", stdin);
  freopen(OuFile, "w", stdout);
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", __gcd(a, b));
  }
  return 0;
}
