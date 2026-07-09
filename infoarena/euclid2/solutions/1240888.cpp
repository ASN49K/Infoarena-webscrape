#include <cstdio>

using namespace std;

long long gcd(long long a, long long b)
{
  if(b == 0)
    return a;

  return gcd(b, a % b);
}

void read()
{
  freopen("euclid2.in", "r", stdin);
  freopen("euclid2.out", "w", stdout);
  long long x, y, N;
  scanf("%lld", &N);
  while(N)
  {
    scanf("%lld%lld", &x, &y);
    if(x > y)
      printf("%lld\n", gcd(x, y));
    else
      printf("%lld\n", gcd(y, x));
    N--;
  }
}

int main()
{
  read();
	return 0;
}
