#include <iostream>

using namespace std;

long long euclid_alg(long long a, long long b) {
  if (b == 0)
    return a;
  return euclid_alg(b, a % b);
}

int main()
{
  freopen("euclid2.in", "r", stdin);
  freopen("euclid2.out", "w", stdout);

  int N;

  scanf("%d", &N);

  for (int i = 0; i < N; ++i) {
    long long a,b;
    scanf("%lld%lld", &a,&b);
    printf("%lld\n", euclid_alg(a,b));
  }

  
  
  return 0;
}
