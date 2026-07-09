#include <cstdio>
#include <algorithm>
int main() {
  freopen("euclid2.in","r",stdin),freopen("euclid2.out","w",stdout);
  int n;
  scanf("%d",&n);
  while(n--){
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d\n", std::__gcd(x, y));}
  return 0;
}
