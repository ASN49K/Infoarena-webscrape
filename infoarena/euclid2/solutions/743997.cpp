#include <cstdio>
using namespace std;
int euc(int a, int b)
{
if(!b)
  return a;
else
  return euc(b, a%b);
}
int main()
{
freopen("euclid2.in", "r", stdin);
freopen("euclid2.out","w",stdout);
int a,b,t;
scanf("%d", &t);
for(;t;--t)
  {
  scanf("%d %d", &a, &b);
  printf("%d\n", euc(a,b));
  }
}

